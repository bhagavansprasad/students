#include "stdio.h"
#include <sys/types.h>
#include <sys/socket.h>
#include "rpc_fop.h"
#include "txrx_rpc_data.h"


int client_sock_fd = -1;

int send_rpcc_client_request(void *pdata, int len)
{
	int retval = 0;

	retval = send(sock_fd, pdata, len);

	printf("send retval :%d\n", retval);
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
	connect(client_sock_fd, (struct sockaddr *) &serverAddr, addr_size);

	return 0;
}
