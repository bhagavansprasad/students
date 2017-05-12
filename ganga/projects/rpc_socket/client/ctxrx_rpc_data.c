#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "../defs/rpc_fop.h"
#include "../defs/ctxrx_rpc_data.h"

int client_sock_fd = -1;

int send_rpcc_client_request(void *pdata, int len)
{
	int retval = -1;

	retval = send(client_sock_fd, pdata, len, 0);

	printf("-->C: send retval :%d\n", retval);
}

int  recv_rpcc_client_reply(void *pdata, int len)
{
	int reply_retval = -1;

	reply_retval = recv(client_sock_fd, pdata, len, 0);

	printf("-->C: recv retval :%d\n", reply_retval);

	return reply_retval;
}

int init_client_connection(char *srvr_addr, int port)
{
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	client_sock_fd = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(9090);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	addr_size = sizeof serverAddr;
	printf("-->C. client: connecting to the server\n");
	connect(client_sock_fd, (struct sockaddr *) &serverAddr, addr_size);

	return 0;
}
