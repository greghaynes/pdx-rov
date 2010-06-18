#include "network.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <signal.h>

#include <linux/videodev2.h>

extern int sock_fd;

struct buffer
{
	void *start;
	size_t length;
};

time_t cur_time_sec;

// Camera capture globals
static int device_fd = 0;
struct buffer *buffers;
static char *device_path = 0;
static int n_buffers = 0;

/* gettimeofday cheat */
static void handle_sigalrm(int code)
{
	struct timeval tv;

	if(-1 == gettimeofday(&tv, 0))
		perror("gettimeofday");
	else
		cur_time_sec = tv.tv_sec;

	alarm(1);
}

static int xioctl(int fd, int request, void *arg)
{
	int r;

	do r = ioctl(fd, request, arg);
	while(-1 == r && EINTR == errno);

	return r;
}

void usage()
{
	printf("Usage: ./jpeg_cannon --device camera_device --sport server_port\n");
}

void help()
{
	printf("Opens a UDP stream which blasts jpegs from a webcam to all clients that say \'hello\' once per second.\n\n");
	usage();
}

static const char short_options [] = "ds:h";

static const struct option long_options [] = {
	{ "device", required_argument, NULL, 'd' },
	{ "help", no_argument, NULL, 'h' },
	{ "sport", required_argument, NULL, 's' },
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

static void process_image (const void *p)
{
	network_broadcast(p, strlen(p));
}

int init_mmap()
{
	struct v4l2_requestbuffers req;

	memset(&req, 0, sizeof(struct v4l2_requestbuffers));
        req.count = 4;
        req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        req.memory = V4L2_MEMORY_MMAP;

	if(-1 == xioctl(device_fd, VIDIOC_REQBUFS, &req))
	{
		if(EINVAL == errno)
		{
			fprintf(stderr, "%s does not support "
				 "memory mapping\n", device_path);
			return 0;
		}
		else
		{
			perror("reqbuffs");
			return 0;
		}
	}

	if(req.count < 2)
	{
		fprintf(stderr, "Insufficient buffer memory on %s\n",
			device_path);
		return 0;
	}

	buffers = calloc(req.count, sizeof(*buffers));
	
	if(!buffers)
	{
		fprintf(stderr, "Out of memory\n");
		return 0;
	}

	for (n_buffers = 0; n_buffers < req.count; ++n_buffers) {
		struct v4l2_buffer buf;

		memset(&buf, 0, sizeof(struct v4l2_buffer));

		buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory      = V4L2_MEMORY_MMAP;
		buf.index       = n_buffers;

		if (-1 == xioctl (device_fd, VIDIOC_QUERYBUF, &buf))
		{
			perror("VIDIOC_QUERYBUF");
			return 0;
		}

		buffers[n_buffers].length = buf.length;
		buffers[n_buffers].start =
			mmap (NULL /* start anywhere */,
			      buf.length,
			      PROT_READ | PROT_WRITE /* required */,
			      MAP_SHARED /* recommended */,
			      device_fd, buf.m.offset);

		if (MAP_FAILED == buffers[n_buffers].start)
		{
			perror("mmap");
			return 0;
		}
	}
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

	if(!(cap.capabilities & V4L2_CAP_STREAMING))
	{
		fprintf(stderr, "Device does not support streaming i/o.\n");
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

	return init_mmap();
}

int read_frame(void)
{
	struct v4l2_buffer buf;
	unsigned int i;

	memset(&buf, 0, sizeof(struct v4l2_buffer));

	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;

	if (-1 == xioctl (device_fd, VIDIOC_DQBUF, &buf)) {
		switch (errno) {
		case EAGAIN:
			return 1;

		case EIO:
			/* Could ignore EIO, see spec. */

			/* fall through */

		default:
			perror("Query read buff");
			return 0;
		}
	}

	assert(buf.index < n_buffers);

	process_image (buffers[buf.index].start);

	if (-1 == xioctl (device_fd, VIDIOC_QBUF, &buf))
	{
		perror("VIDIOC_QBUF");
		return 0;
	}

	return 1;
}

int start_capture()
{
	unsigned int i;
	enum v4l2_buf_type type;

	for (i = 0; i < n_buffers; ++i) {
		struct v4l2_buffer buf;

		memset(&buf, 0, sizeof(struct v4l2_buffer));

		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		if(-1 == xioctl(device_fd, VIDIOC_QBUF, &buf))
		{
			perror("VIDIOC_QBUF");
			return 0;
		}
	}
	
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if(-1 == xioctl(device_fd, VIDIOC_STREAMON, &type))
	{
		perror("VIDIOC_STREAMON");
		return 0;
	}

	return 1;
}

int main(int argc, char **argv)
{
	short int sport;

	signal(SIGALRM, handle_sigalrm);
	handle_sigalrm(SIGALRM);

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
			case 's':
				sport = atoi(optarg);
				break;
			case 'h':
				help();
				exit(EXIT_SUCCESS);
		}
	}

	// Init video
	if(!device_path)
	{
		usage();
		exit(EXIT_FAILURE);
	}

	if(!open_device(device_path)
		|| !init_device())
		exit(EXIT_FAILURE);

	if(!start_capture())
		exit(EXIT_FAILURE);

	// Init network
	if(!network_init(sport))
		exit(EXIT_FAILURE);

	while(1)
	{
		fd_set r_fds, w_fds;
		struct timeval tv;
		int r;

		FD_ZERO(&r_fds);
		FD_ZERO(&w_fds);
		FD_SET(device_fd, &r_fds);
		FD_SET(sock_fd, &r_fds);

		/* Timeout. */
		tv.tv_sec = 2;
		tv.tv_usec = 0;

		r = select (device_fd + 1, &r_fds, NULL, NULL, &tv);

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

		if(FD_ISSET(sock_fd, &r_fds))
			network_handle_read();

		if(FD_ISSET(device_fd, &r_fds))
		{
			if(!read_frame())
				break;
		}

	}

	return 0;
}

