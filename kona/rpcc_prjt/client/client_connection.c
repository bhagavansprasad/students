#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"unistd.h"
#include "error.h"
#include "stdlib.h" 
#include "struct_client.h"
#include "struct_server.h"
#include <fcntl.h>
int socketfd=-1;
void client_req(void)
{
	int connected;
	struct sockaddr_in myclientaddr;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client: Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(6666);

	printf("--->client: Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
if(connected == -1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}
	
}
int client(struct ch *q)
{
//	printf("%s %d\n",__FILE__,__LINE__);
	int retval;
	retval=write(socketfd,q,sizeof(struct ch));
	printf("--->client: write retval:%d\n",retval);
	return (retval);
}
int client_read(struct server *y)
{
	int retval;
	retval=read(socketfd,y,sizeof(struct server));
	printf("--->client: read retval from server:%d\n",retval);
	return (retval);
}
