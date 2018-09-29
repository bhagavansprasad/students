#include<sys/types.h>
#include<sys/socket.h>
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
int main()
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	//char buff1[3][20]={"hellow","i am fine","bye"};
	char buff1[100];
	char buffer[100];
	int newfd;
	int retval=0,i;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to creat a socket \r\n");
		exit(1);
	}
	memset(&mysockaddr,0,sizeof(mysockaddr));
	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(5555);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;
	if(bind(socketfd,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr))==-1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen system call failed\r\n ");
		close(socketfd);
		exit(1);
	}
	printf("--->server: going for accepting connection\r\n");
	while(1)
	{
		newfd=accept(socketfd,NULL,NULL);
		if(newfd==-1)
		{
			perror("accept system call failed\r\n");
			close(socketfd);
			exit(1);
		}
		printf("---->server :got the connection request from client\r\n\n");
		while(1)
		{
			sleep(2);
			retval=read(newfd,buffer,30);
			if(retval<0)
			{
				break;
			}
			buffer[retval]='\0';
			printf("---->server :receive from client :%s\r\n",buffer);
			printf("enter a message to sent client :\n");
			gets(buff1);
			if(strcmp(buffer,"bye")==0)
			{
				retval=write(newfd,&buff1,30);
				break;
			}
			else
				retval=write(newfd,&buff1,30);
		}
	}
	close(socketfd);
	return(0);
}
