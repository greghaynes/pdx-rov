#include <event.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct client
{
	struct client *next;
	int fd;
	struct sockaddr_in sa;
	struct event ev;
};

struct server
{
	struct event ev;
	int fd;
	struct sockaddr_in sa;
	struct client *clients;
};

static struct server srv;

void on_read(int fd, short event, void *data)
{
	char buff[256];
	int len;
	while((len = read(fd, &buff, 255)) == 255);
	if(len == 0)
	{
		struct client *ci, *pci;
		pci = 0;
		ci = srv.clients;
		while(ci && ci != data)
		{
			pci = ci;
			ci = ci->next;
		}
		if(ci != data)
			fprintf(stderr, "Recieved read from non-stored connection");
		else
		{
			if(pci)
				pci->next = ci->next;
			else
				srv.clients = 0;
			close(ci->fd);
			free(ci);
		}
	}
	else
		event_add(&((struct client*)data)->ev, 0);
}

void on_connect(int fd, short event, void *data)
{
	printf("New connection.\n");
	struct server *srv = (struct server*)data;
	struct client *cl = malloc(sizeof(struct client));
	socklen_t size = sizeof(struct sockaddr);

	cl->next = srv->clients;
	srv->clients = cl;
	cl->fd = accept(srv->fd, (struct sockaddr*)&cl->sa,
		&size);
	if(cl->fd != -1)
	{
		event_set(&cl->ev,
			cl->fd, EV_READ, on_read, cl);
		event_add(&cl->ev, 0);
	}
	else
		perror("Accepting connection");
	
	event_add(&srv->ev, 0);
}

int main(char **argv, int argc)
{
	event_init();

	srv.sa.sin_family = AF_INET;
	srv.sa.sin_port = htons(8081);
	srv.fd = socket(AF_INET,
		SOCK_STREAM | SOCK_NONBLOCK, 0);
	if(srv.fd == -1)
	{
		perror("Creating socket");
		return 1;
	}

	if(bind(srv.fd, (struct sockaddr*)&srv.sa, sizeof(struct sockaddr)) == -1)
	{
		perror("Binding to host");
		return 1;
	}
	
	event_set(&srv.ev,
		srv.fd, EV_READ, on_connect, &srv);
	event_add(&srv.ev, 0);

	listen(srv.fd, 4);
	event_dispatch();

	// Delete clients
	struct client *ci = srv.clients;
	struct client *prev_ci;
	while(ci)
	{
		prev_ci = ci;
		ci = ci->next;
		close(prev_ci->fd);
		free(prev_ci);
	}

	close(srv.fd);
	
	return 0;
}

