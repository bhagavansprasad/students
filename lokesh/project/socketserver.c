#include"sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include"stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include"errno.h"
#include"string.h"
#include "sys/types.h"

int main(void)
{

	struct sockaddr_in mysockaddr;
	int socketfd;
	char buff1[10][30] = {"hellow","i am fine ","what is ur name","how u","how is it"};
	char b1[10]="bye";
	char buffer[100];

	int newfd;
	int retval=0,i;
	int read_retval;
	char t;

	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("failed to create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr,0,sizeof(mysockaddr));

	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(6666);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;


	if(bind(socketfd,(struct sockaddr*)&mysockaddr,sizeof(mysockaddr))==-1)
	{

		perror("bind system call failed \r \n");
		close(socketfd);
		exit(1);

	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen  system call failed \r \n");
		close(socketfd);
		exit(1);
	}
	printf("-->server :going for accepting connection \r\n");
	newfd=accept(socketfd,NULL,NULL);
	if(newfd==-1)
	{
		perror("accept system call failed \r \n");
		close(socketfd);
		exit(1);
	}
	printf("-->server :got the connection request from client  \r\n\n");
	for(i=0;i<10;i++)
	{
	
		retval=read(newfd,buffer,30);
		if(read_retval ==-1)
		{
			perror("read failed ");
			exit(0);
		}
		
		printf("-->server :receive from client :%s \r\n",buffer);
		t=strcmp(buffer,"bye");
		if(t==0)
		{
		exit(0);
		}
		retval=write(newfd,&buff1[i],30);
		printf("server: buff1 write retval :%d\n",retval);
		if(retval ==-1)
		{
		perror("write failed");
		exit(0);
		}
		if(strcmp(buff1[i],"bye")==0)
		{
		exit(0);
		}
	}
	close(socketfd);
	return 0;
}

