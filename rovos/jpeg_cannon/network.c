#include "network.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define TIMEOUT_SECS 3

extern cur_time_sec;

struct client
{
	struct sockaddr_in si_addr;
	time_t last_hello_sec;
	struct client *next;
};

// Network globals
int sock_fd = 0;
struct sockaddr_in si_src;
struct client *clients = 0;

int network_init(short unsigned int port)
{
	sock_fd = socket(PF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);

	memset(&si_src, 0, sizeof(struct sockaddr_in));
	si_src.sin_family = AF_INET;
	si_src.sin_port = htons(port);
	si_src.sin_addr.s_addr = INADDR_ANY;

	if(-1 == bind(sock_fd, (struct sockaddr*)&si_src, sizeof(struct sockaddr_in)))
	{
		perror("bind");
		close(sock_fd);
		return 0;
	}
}

void network_client_remove(struct client *client)
{
	struct client *prev = 0, *itr = clients;

	while(itr)
	{
		if(itr == client)
		{
			if(prev)
				prev->next = itr->next;
			else
				clients = 0;

			free(client);
		}
	}
}

void network_check_client(struct client *client)
{
	if((client->last_hello_sec + TIMEOUT_SECS) < cur_time_sec)
		network_client_remove(client);
}

void network_check_clients()
{
	struct client *itr = clients;
	while(clients)
	{
		network_check_client(itr);
		clients = clients->next;
	}
}

void network_client_hello(struct sockaddr_in *addr)
{
	struct client *new_cli = malloc(sizeof(struct client));

	new_cli->next = clients;
	clients = new_cli;
	memcpy(&new_cli->si_addr, addr, sizeof(struct sockaddr_in));
	new_cli->last_hello_sec = cur_time_sec;
}

void network_handle_read()
{
	char buffer[1024];
	int len, addr_len = sizeof(struct sockaddr_in);
	struct sockaddr_in addr;

	len = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
	if(strncmp(buffer, "hello", 5))
		network_client_hello(&addr);
}

void network_broadcast(const char *data, int len)
{
	struct client *itr = clients;

	printf("Broadcasting msg size: %i\n", len);

	while(itr)
	{
		if(-1 == sendto(sock_fd, data, len, 0,
			(struct sockaddr*)&itr->si_addr, sizeof(struct sockaddr)))
			perror("Sending broadcast");
		itr = itr->next;	
	}
}

