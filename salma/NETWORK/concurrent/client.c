#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
main()
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	//char buff1[3][20]={"hi aura","how are you","bye"};
	char buff1[100];
	char sbuff[1024];
	int retval=0,i=0;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("--->client:failed to creat a socket\n");
		exit(1);
	}
	myclientaddr.sin_family=AF_INET;
	myclientaddr.sin_addr.s_addr=inet_addr("192.168.1.30");
	myclientaddr.sin_port=htons(1111);
	printf("--->client:connecting to the server\n");
	connected=connect(socketfd,(struct sockaddr
				*)&myclientaddr,sizeof(myclientaddr));
	if(connected ==-1)
	{
		perror("--->client: connect system call failed\n");
		close(socketfd);
		exit(1);
	}
	while(1)
	{
		sleep(2);
		printf("enter a message to send for a server :\n");
		gets(buff1);
		retval=write(socketfd,&buff1[i],20);
		if(retval<0)
		{
			break;
		}
		retval=read(socketfd,sbuff,sizeof(sbuff));
		if(retval<0)
		{
			break;
		}
		sbuff[retval]='\0';
		printf("--->client :buffer read from server :%s\n",sbuff);
		if(strcmp(sbuff,"bye")==0)
			break;
	}
	close(socketfd);
	return(0);
}
