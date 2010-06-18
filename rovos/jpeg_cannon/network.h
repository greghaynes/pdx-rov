int network_init(short unsigned int port);

void network_check_clients();

void network_handle_read();

void network_broadcast(const char *data, int len);

