#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "arpc.h"

int socketfd = -1;

int init_net_comm(int port, char *srvr_ip)
{
	int connected;
	struct sockaddr_in myclientaddr;
	//char sbuff[1024];
	//int retval = 0;
	//int read_retval;
	//char t;

	socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		printf("\n--> client :could not creat socket \n");
		exit(1);
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_port = htons(port);
	myclientaddr.sin_addr.s_addr = inet_addr(srvr_ip);

	printf("-->client:connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("-->client : Connect system call failed \n");
		close(socketfd);
		exit(1);
	}
	return socketfd;
}

int rpcc_send_data(fopdata_req *req)
{
	int retval = -1;

	retval = write(socketfd, req, sizeof(fopdata_req));

	printf("-->In rpcc: socket write retval :%d\n", retval);

	return retval;
}

int read_from_server(fopdata_rep *psreply)
{
	int retval = -1;

	retval = read(socketfd, psreply, sizeof(fopdata_rep));
printf("client read retval = %d\n",retval);
	return retval;
}
