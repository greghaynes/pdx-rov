#include "request.h"

#include <stdio.h>

void request_get(struct client *client,
	const char *var_name)
{
	printf("get\n");
}

void request_set(struct client *client,
	const char *var_name,
	const char *value)
{
	printf("set\n");
}

