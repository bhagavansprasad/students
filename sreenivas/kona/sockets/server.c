#include"sys/types.h"
#include"sys/socket.h"
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
	char buff1[3][15]={"hello","mangalore","kadapa"};
	char buff[100];
	int newfd;
	int retval=0,i;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("falied to create a socket \r\n");
			exit(1);
	}
	memset(&mysockaddr,0,sizeof(mysockaddr));
	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(6666);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;
	
	if(bind(socketfd,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr))==-1)
	{
		perror("bind system call falied\r\n");
		close(socketfd);
		exit(1);
	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen system call falied\r\n");
		close(socketfd);
		exit(1);
	}
	while(1)
	{
	printf("---->server:going for accepting connection\r\n");
	newfd=accept(socketfd,NULL,NULL);
	if(newfd==-1)
	{
		perror("accept system call falied\r\n");
		close(socketfd);
		exit(1);
	}
	printf("--->server:Got the connection request from client\r\n\n");
	for(i=0;i<3;i++)
	{
		retval=read(newfd,buff,30);
		if(retval<0)
		{
			break;
		}
		buff[retval]='\0';
		printf("---->server:receive from client :%s\r\n",buff);
		retval=write(newfd,&buff1[i],20);
		if(retval<0)
		{
			break;
		}
		printf("--->server:buff1 write retval:%d\n",retval);
	}
	}
	close(socketfd);
	return 0;
}

