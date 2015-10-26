#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "struct.h"
#include "second_struct.h"

int socketfd = -1;
int newfd = -1;

int socket_server_init()
{
	struct sockaddr_in mysockaddr;
	int retval = 0,i;
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(8888);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	printf("--->server : Got the connection request from client \r\n\n");
}


int server_read(struct students *stud)
{

	sleep(2);
	int retv_read;
	retv_read = read(newfd, stud,sizeof(struct students));
	printf("server read return value:::--->%d\n",retv_read);
	return retv_read;
}


int server_write(struct school *sch)
{
	int retv_write;
	retv_write = write(newfd, sch,sizeof(struct school));
	printf("--->server:  write retval : %d\n",retv_write);
	return retv_write;
}
