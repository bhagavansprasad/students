#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"strc.h"
#include"struct.h"
int newfd=-1;
int socketfd=-1;
void server_recev(void)
{
	struct sockaddr_in mysockaddr;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("failed to creat a socket \n");
		exit(0);
	}
	memset(&mysockaddr,0,sizeof(mysockaddr));
	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(7777);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;
	if(bind(socketfd,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr))==-1)
	{
		perror("bind system call failed \n");
		close(socketfd);
		exit(1);
	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen system call failed \n");
		close(socketfd);
		exit(1);
	}
	printf("----->server : going for accepting connection \n");
	newfd=accept(socketfd,NULL,NULL);
	if(newfd==-1)
	{
		perror("accept system call failed\n");
		close(socketfd);
		exit(1);
	}
	printf("-----> got the connection request from client\n");
}
int server_read(struct ch *q)
{
	int retval;
	retval=read(newfd,q,sizeof(struct ch));
	printf("---->server :receive from client:%d\n",retval);
}
int server_write(struct server *y)
{
	int retval;
	retval=write(newfd,y,sizeof(struct server));
	printf("--->server:write to client:%d\n",retval);
}
