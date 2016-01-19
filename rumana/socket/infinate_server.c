#include"stdio.h"
#include "sys/types.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include"unistd.h"
#include "sys/socket.h"

main()
{
	int socketfd;
	struct sockaddr_in mysockaddr;
	char cbuff[100];
	char buffer[100];
	int newfd;
	int retval=0,i;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("----->server: failed to create a socket\n");
		exit(1);
	}
	memset(&mysockaddr,0,sizeof(mysockaddr));
	mysockaddr.sin_family=AF_INET;
	mysockaddr.sin_port=htons(8111);
	mysockaddr.sin_addr.s_addr=INADDR_ANY;
	if(bind(socketfd,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr))==-1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	if(listen(socketfd,5)==-1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	printf("server:going for accepting connection\r\n");

	newfd=accept(socketfd,NULL,NULL);
	if(newfd==-1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}
	printf("------->server:got the connection request from client\r\n\n");
	printf("begin chat\n");
	while(1)
	{
		sleep(2);
		retval=read(newfd,buffer,30);
		if(retval<0)
		{
			break;
		}
		buffer[retval]='\0';
		printf("%s\n",buffer);
		gets(cbuff);
		retval=write(newfd,cbuff,20);
		if(retval<0)
		{
			break;
		}
		if(strcmp(buffer,"bye")==0)
		break;
	}
	close(socketfd);

}
