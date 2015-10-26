#include <sys/types.h>
#include "unistd.h"
#include "netinet/in.h"
#include <stdio.h>
#include "arpa/inet.h"
#include "stdlib.h" 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include "structure.h"
int clientsocket;

int init_netc_communication(char *srvr_ip, int srvr_port)
{
	int connectfd;
	struct sockaddr_in clientaddr;
	clientsocket = socket(AF_INET, SOCK_STREAM, 0);

	if(clientsocket < 0)
	{
		perror("--->client : creation of client socket is failed \n");
		printf("client socket errno = %d\n",errno);
		exit(1);
	}
	printf("--->client : client socket is  created successively\n");

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	clientaddr.sin_port = htons(srvr_port);
	printf("--->client : connecting to the server... .. .\n");
	connectfd = connect(clientsocket, (struct sockaddr *)&clientaddr,sizeof(clientaddr));
	if(connectfd < 0)
	{
		perror("--->client : connecting to server is failed \n");
		printf("client connect errno = %d\n",errno);
		close(clientsocket);
		exit(1);
	}
	printf("--->client : got the connection b/w client and server\n\n");

	return clientsocket;
}

int client_write_to_server(fop_data_req *creq)
{
	int wretval;
	printf("    ------*******------\n");
	wretval = write(clientsocket, creq, sizeof(fop_data_req));
	printf("CLIENT : client sending data retval........................... =  %d\n",wretval);

	return wretval;
}

int client_read_from_server(fop_data_rep *sreplay)
{
	int rretval;

	rretval = read(clientsocket, sreplay, sizeof(fop_data_rep));
	printf("CLIENT : client recieving data retvalue....................... =  %d\n",rretval);

	return rretval;
}

int close_intc_communication(void)
{
	close(clientsocket);
	return 0;
}

