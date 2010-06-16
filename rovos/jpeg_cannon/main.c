#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

static int device_fd = 0;

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

	if(!open_device(device_path))
		exit(EXIT_FAILURE);

	return 0;
}

