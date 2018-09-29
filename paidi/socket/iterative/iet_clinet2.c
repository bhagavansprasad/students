#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
int returnval=0;
int main(void)
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char cbuff[1024]="hi aura network";
	char sbuff[1024];
	int retval=0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("--->client2 : Failed to create a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(7777);

	printf("--->client2 : Connecting to the server\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client2 : connect system call failed\n");
		exit(1);
	}

	while(1)
	{ 
        sleep(1); 
		retval=write(socketfd, cbuff,20);
		if(retval < 0)
		{
			break;
			close(socketfd);
		}

		retval=read(socketfd, sbuff, 20);
		if(retval < 0)
		{
			break;
			close(socketfd);
		}

		printf("--->client2 : buffer read from server:%s\n",sbuff);
	}
	close(socketfd);
	return 0;

}
