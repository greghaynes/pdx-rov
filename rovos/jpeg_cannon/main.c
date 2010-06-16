#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <linux/videodev2.h>

struct buffer
{
	void *start;
	size_t length;
};

static int device_fd = 0;
struct buffer device_buffer;

static int xioctl(int fd, int request, void *arg)
{
	int r;

	do r = ioctl(fd, request, arg);
	while(-1 == r && EINTR == errno);

	return r;
}

void usage()
{
	printf("Usage: ./jpeg_cannon -d device\n");
}

void help()
{
	printf("Opens a UDP stream which blasts jpegs from a webcam to all clients that say \'hello\' once per second.\n\n");
	usage();
}

static const char short_options [] = "d:h";

static const struct option long_options [] = {
	{ "device", required_argument, NULL, 'd' },
	{ "help", no_argument, NULL, 'h' },
	{ 0, 0, 0, 0, }
	};

int open_device(const char *device_path)
{
	struct stat st;

	if(-1 == stat(device_path, &st))
	{
		fprintf(stderr, "Could not open device.\n");
		return 0;
	}

	if(!S_ISCHR(st.st_mode))
	{
		fprintf(stderr, "Device is not the correct type.\n");
		return 0;
	}

	device_fd = open(device_path, O_RDWR | O_NONBLOCK, 0);
	return 1;
}

int init_device()
{
	struct v4l2_capability cap;
	struct v4l2_cropcap cropcap;
	struct v4l2_crop crop;
	struct v4l2_format fmt;
	unsigned int min;

	if(-1 == xioctl(device_fd, VIDIOC_QUERYCAP, &cap))
	{
		if(errno == EINVAL)
		{
			fprintf(stderr, "Not a valid v4l2 device\n");
			return 0;
		}
		else
		{
			perror("Detecting device capability");
			return 0;
		}
	}

	if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
	{
		fprintf(stderr, "Not a valid video capture device.\n");
		return 0;
	}

	if(!(cap.capabilities & V4L2_CAP_READWRITE))
	{
		fprintf(stderr, "Device does not support read i/o.\n");
		return 0;
	}

	memset(&cropcap, 0, sizeof(struct v4l2_cropcap));
	cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if(0 == xioctl(device_fd, VIDIOC_CROPCAP, &cropcap))
	{
		crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		crop.c = cropcap.defrect; // Set to default

		if(-1 == xioctl(device_fd, VIDIOC_S_CROP, &crop))
		{
			// Errors ignored
		}
	}
	else
	{
		// Errors ignored
	}

	// Set capture format
	memset(&fmt, 0, sizeof(struct v4l2_format));
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        fmt.fmt.pix.width = 640; 
        fmt.fmt.pix.height = 480;
        fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;
        fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;

	if(-1 == xioctl(device_fd, VIDIOC_S_FMT, &fmt))
	{
		perror("Setting device format");
		return 0;
	}

	// Buggy driver voodoo
	min = fmt.fmt.pix.width * 2;
	if(fmt.fmt.pix.bytesperline < min)
		fmt.fmt.pix.bytesperline = min;
	min = fmt.fmt.pix.bytesperline * fmt.fmt.pix.height;
	if(fmt.fmt.pix.sizeimage < min)
		fmt.fmt.pix.sizeimage = min;

	// Initialize buffer
	device_buffer.length = fmt.fmt.pix.sizeimage;
	device_buffer.start = malloc(fmt.fmt.pix.sizeimage);

	if(!device_buffer.start)
	{
		fprintf(stderr, "Out of memory!\n");
		return 0;
	}

	return 1;
}

int read_frame(void)
{
	struct v4l2_buffer buf;
	unsigned int i;

	if(-1 == read(device_fd, device_buffer.start, device_buffer.length))
	{
		if(errno != EAGAIN)
		{
			perror("Reading frame");
			return 0;
		}
	}

	return 1;
}

int main(int argc, char **argv)
{
	char *device_path = 0;

	// Argument Processing
	while(1)
	{
		int c, index;

		c = getopt_long(argc, argv,
			short_options, long_options,
			&index);

		if(c == -1)
			break;

		switch(c)
		{
			case 0:
				break;
			case 'd':
				device_path = optarg;
				break;
			case 'h':
				help();
				exit(EXIT_SUCCESS);
		}
	}

	if(!device_path)
	{
		usage();
		exit(EXIT_FAILURE);
	}

	if(!open_device(device_path)
		|| !init_device())
		exit(EXIT_FAILURE);

	while(1)
	{
		fd_set fds;
		struct timeval tv;
		int r;

		FD_ZERO (&fds);
		FD_SET (device_fd, &fds);

		/* Timeout. */
		tv.tv_sec = 2;
		tv.tv_usec = 0;

		r = select (device_fd + 1, &fds, NULL, NULL, &tv);

		if (-1 == r) {
			if (EINTR == errno)
				continue;

			perror("select");
			exit(EXIT_FAILURE);
		}

		if (0 == r) {
			fprintf (stderr, "select timeout\n");
			exit (EXIT_FAILURE);
		}

		if(!read_frame())
			break;
		else
			printf(".");
	}

	return 0;
}

