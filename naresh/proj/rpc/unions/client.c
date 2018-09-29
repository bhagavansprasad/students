#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>


int main(void)
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
	char buff1[10][20] = {"hai naresh","how are you","happy","bye","test","hai"};
	char sbuff[1024];
	int retval = 0,i = 0;
	int read_retval;
	char t;

	socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		printf("\n--> client :could not creat socket \n");
		return 1;
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_port = htons(7777);
	myclientaddr.sin_addr.s_addr = inet_addr("198.168.1.255");

	printf("-->client:connecting to the server\n");
	connected=connect(socketfd,(struct sockaddr*)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("-->client : Connect system call failed \n");
		close(socketfd);
		exit(1);
	}
}
{
	for(i = 0;i < 10;i++)
	{
		sleep(1);
		retval = write(socketfd,&buff1[i],20);
		printf("retval of write: %d\n",retval);
		if(retval == -1)
		{
			perror("write failed");
			exit(0);
		}

		read_retval = read(socketfd,sbuff,sizeof(sbuff));
		if(read_retval == -1)
		{
			perror("read failed");
			exit(0);
		}
		
		printf("-->client: buffer read from servor :%s\r\n",sbuff);
		
		t = strcmp(sbuff,"bye");
		if(t == 0)
		{
			exit(0);
		}
		
	}
	close(socketfd);
		return 0;
}
}

