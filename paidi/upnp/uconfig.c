#include "uconfig.h"
#include "stdio.h"
#include "string.h"
#include "udp.h"

int get_upnp_multicast_ip(char *ip)
{
	strcpy(ip, UPNP_MULTICAST_IP);

	return 0;
}

int get_upnp_server_port(void)
{
	return UPNP_SERVER_PORT;
}

int get_upnp_server_ip(char *ip)
{
	strcpy(ip, UPNP_SERVER_IP);

	return 0;
}

