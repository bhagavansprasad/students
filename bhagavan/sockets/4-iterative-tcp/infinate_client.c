#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdio.h"
#include"stdlib.h"
#include "string.h"
#include "unistd.h"
main()
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char sbuff[1024];
	char buff1[20];
	int retval=0,i=0;

	socketfd=(AF_INET,SOCK_STREAM,0);
	if(socketfd==-1)
	{
		perror("----->client:failed to create socket fd\n");
		exit(1);
	}
	myclientaddr.sin_family=AF_INET;
	myclientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	myclientaddr.sin_port=htons(8111);

	printf("------>client:connecting to the server\n");
	connected=connect(socketfd,(struct sockaddr *)&myclientaddr,sizeof(myclientaddr));
	if(connected==-1)
	{
		perror("-------->client:connect system call failed\n");
		close(socketfd);
		exit(1);
	}
	printf("begin chat");
	while(1)
	{
		sleep(2);
		gets(buff1);
		retval=write(socketfd,buff1,20);
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
		printf("%s",sbuff);
		if(strcmp(sbuff,"bye")==0)
		break;
	}
	close(socketfd);

}
