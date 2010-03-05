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
};

struct server
{
	struct event ev;
	int fd;
	struct sockaddr_in sa;
	struct client *clients;
};

void on_connect(int fd, short event, void *data)
{
	printf("New connection.\n");
	struct server *srv = (struct server*)data;
	struct client *cl = malloc(sizeof(struct client));

	cl->next = srv->clients;
	srv->clients = cl;
	cl->fd = accept(srv->fd, (struct sockaddr*)&cl->sa,
		sizeof(struct sockaddr));
	
	event_add(&((struct server*)data)->ev, 0);
}

int main(char **argv, int argc)
{
	event_init();

	struct server srv;
	srv->clients = 0;

	memset(&srv.sa, 0, sizeof(struct sockaddr_in));
	srv.sa.sin_family = AF_INET;
	srv.sa.sin_port = htons(8081);
	srv.fd = socket(AF_INET,
		SOCK_STREAM | SOCK_NONBLOCK, 0);
	bind(srv.fd, (struct sockaddr*)&srv.sa, sizeof(struct sockaddr));
	
	event_set(&srv.ev,
		srv.fd, EV_READ, on_connect, &srv);
	event_add(&srv.ev, 0);

	listen(srv.fd, 4);
	event_dispatch();

	// Delete clients
	struct client *ci = srv->clients;
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

