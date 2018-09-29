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
#include "defs.h"

int main(void)
{
	int socketfd;
	int connected;
	struct sockaddr_in myclientaddr;
//	char buff[10][20] = {"hai ","who are you","how are you","banglore","test","bye"};
//	char reply[1024];
	int retval = 0,i = 0;
	int read_retval;
	char t;
	struct data cdata= {20, "Rajini"};
	struct reply_data rdata;

	socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		printf("\n--> client :could not creat socket \n");
		return 1;
	}
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_port = htons(7777);
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("-->client:connecting to the server\n");
	connected=connect(socketfd,(struct sockaddr*)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("-->client : Connect system call failed \n");
		close(socketfd);
		exit(1);
	}

//	for(i = 0;i < 10;i++)
//	{
		retval = write(socketfd, &cdata, sizeof(cdata));
		printf("retval of write: %d\n",retval);
		if(retval == -1)
		{
			perror("write failed");
			exit(0);
		}

#if 0
	   	if(strcmp(buff[i],"bye")==0)
		{
			exit(0);
		}
#endif

		read_retval = read(socketfd, &rdata, sizeof(rdata));
		if(read_retval == -1)
		{
			perror("read failed");
			exit(0);
		}
		
//	   	if(strcmp(reply, "bye")==0)
		{
//			exit(0);
		}
		printf("-- > age : %d\tname : %s\tsreply:%s\n",rdata.age,rdata.name,rdata.sreply);
	     //printf("client :struct from server %s\n",rdata);
		//printf("-->client: buffer read from servor :%s\r\n",reply);
		
//	}
	close(socketfd);
		return 0;
}

