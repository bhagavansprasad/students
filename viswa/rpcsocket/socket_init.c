#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
//#include "prototypes.h"
#include "struct.h"
#include "second_struct.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int socketfd = -1;

int  socket_init()
{
	int  connected ,retval=0 ,i=0;
	struct sockaddr_in  myclientaddr;
	socketfd =socket(AF_INET, SOCK_STREAM , 0);
	if(socketfd == -1)
	{
		perror("---->:client failed to connect with server:\n");
		exit(1);
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(8888);
	printf("--->:client ::: connecting to server:\n");
	connected = connect(socketfd, ( struct sockaddr *)&myclientaddr ,sizeof(myclientaddr));
	if (connected ==-1)
	{
		perror("---->:client: failed to system call:\n");
		close(socketfd);
		exit(1);
	}
	return 0;
}


int  client_write(struct students *stud)
{
	int retval;
	retval = write( socketfd , stud , sizeof(struct students ));
	printf("client_write ::retval::--->%d",retval);
	return retval;
}


int client_read( struct school *sch )
{
	int retval;
	retval = read(socketfd , sch , sizeof(struct school ));
	printf("client read data from server :->%d\n",retval);
	return retval;
}
