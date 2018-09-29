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
	int array[3];
	char buff1[3][15]={"hello","mangalore","bye"};
	char buff[100];
	int newfd;
	int retval=0,i=0;
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
		for(i=0;i<3;i++)
		{
			newfd=accept(socketfd,NULL,NULL);
			printf("the new fd value is %d\n",newfd);
			array[i]=newfd;
			if(newfd==-1)
			{
				perror("accept system call falied\r\n");
				close(socketfd);
				exit(1);
			}
		}

			printf("--->server:Got the connection request from client\r\n\n");
			while(1)
			{
				retval=read(array[0], buff, 30);

				if(retval<0)
				{
					break;
				}
				buff[retval]='\0';
				printf("---->server:receive from client :%s\r\n",buff);
				retval=write(array[0], buff1[i], 20);
				if(retval<0)
				{
					break;
				}
				i++;
				printf("--->server:buff1 write retval:%d\n",retval);
				if(strcmp(buff,"bye")==0)
					break;

				sleep(2);
			}
		}
	i=0;
}
close(socketfd);
return 0;
}

