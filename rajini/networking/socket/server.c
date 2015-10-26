#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "def.h"

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	int newfd;
	int retval=0,i;
	int read_retval;
	char t;
	struct data cdata;
	struct reply_data rdata={25,"venky","day"};

	socketfd = socket (AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("failed to creat a socket \r\n");
		exit(1);
	}

//	memset(&mysockaddr,0,sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = INADDR_ANY;
	mysockaddr.sin_port = htons(7777);

	if(bind(socketfd, (struct sockaddr*)&mysockaddr, sizeof(mysockaddr))==-1)
	{
		perror("bind system call failed \r \n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd,5)==-1)
	{
		perror("listen  system call failed \r \n");
		close(socketfd);
		exit(1);
	}

	printf("-->server :going for accepting connection \r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed \r \n");
		close(socketfd);
		exit(1);
	}

	printf("-->server :got the connection request from client  \r\n\n");

//	for(i=0;i<10;i++)
//	{
		read_retval = read(newfd, &cdata, sizeof(cdata));
		
		if(read_retval == -1)
		{
			perror("read failed");
			exit(0);
		}
		printf("age : %d\t,name:%s\n",cdata.age,cdata.name);
		//printf("the data from the client : %s\n", buffer);


		//t = strcmp(buffer, "bye");
//		if(t == 0)
//		{
//			exit(0);
//		}
		
		//sprintf(sreply, "I am server: got the question %s", buffer);
		retval=write(newfd, &rdata, sizeof(rdata));
		printf("server: data write retval :%d\n", retval);
		
		if(retval == -1)
		{
			perror("write failed");
			exit(0);
		}
//	}
	close(socketfd);
	return 0;
}
