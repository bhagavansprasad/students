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
	int fd2;
	int connected;
	struct sockaddr_in myclientaddr;
	char cbuff[50]="my aura network";
	char sbuff[50];

	fd2 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd2 == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(7777);

	printf("client1 : Connecting to the server\r\n");
	connected = connect(fd2, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}

	while(1)
	{ 
		returnval = write(fd2, cbuff, sizeof(cbuff));
		if(returnval<0)
		{
			exit(1);
		}
		returnval = read(fd2, sbuff, sizeof(sbuff));
		if(returnval<0)
		{
			exit(1);
		}	
		printf("cline1-->= %d clint read from server:  %s\r\n",__LINE__,sbuff);
	}
	close(fd2);
	return 0;

}
