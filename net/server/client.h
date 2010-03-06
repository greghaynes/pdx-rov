#ifndef CLIENT_H
#define CLIENT_H

#include <event.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

struct client
{
	int buff_len;
	struct client *next;
	int fd;
	struct event ev;
	struct sockaddr_in sa;
	char buff[512];
};

#endif

