#include "client.h"
#include "request.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

struct server
{
	int fd;
	struct client *clients;
	struct event ev;
	struct sockaddr_in sa;
};

static struct server srv;

void line_recieved(struct client *client, char *line)
{
	char *itr;
	char *var_name = line;
	char *val;
	char ctl;

	itr = line;
	while(*itr && isalnum(*itr)) itr++;
	if(!*itr)
	{
		fprintf(stderr, "Invalid command: No control char found.\n");
		return;
	}

	ctl = *itr;
	*itr = '\0';
	if(ctl == '?')
		request_get(client, var_name);
	else if(ctl == '=')
	{
		itr++;
		val = itr;
		while(*itr && *itr != '\n')
		*itr = '\0';
		request_set(client, line, val);
	}
	else
		fprintf(stderr, "Invalid command: Unsupported control char found.\n");
}

void parse_received_chunk(struct client *client, char *buff, int len)
{
	//TODO buffer appending
	line_recieved(client, buff);
}

void on_read(int fd, short event, void *data)
{
	int len;
	char buff[512];

	len = read(fd, &buff, 511);
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
			fprintf(stderr, "Recieved read from non-stored connection.\n");
		else
		{
			printf("Closing connection.\n");
			if(pci)
				pci->next = ci->next;
			else
				srv.clients = 0;
			close(ci->fd);
			free(ci);
		}
	}
	else
	{
		buff[len] = '\0';
		parse_received_chunk((struct client*)data, &buff, len);
		event_add(&((struct client*)data)->ev, 0);
	}
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

