#ifndef REQUEST_H
#define REQUEST_H

#include "client.h"

void request_get(struct client *client,
	const char *var_name);

void request_set(struct client *client,
	const char *var_name,
	const char *value);

#endif

