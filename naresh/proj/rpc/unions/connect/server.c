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
#include "struct.h"

int rpcs_fop(fopdata *pcdata)
{
	switch(pcdata->fope)
	{
		case OPEN_REQ:
			break;
		case READ_REQ:
			break;
		case WRITE_REQ:
			break;
		case LSEEK_REQ:
			break;
		case CLOSE_REQ:
			break;

	}
}
	
int init_network_comm(int port, char * srvr_ip)
{
}

int main(void)
{
	struct sockaddr_in mysockaddr;
	int socketfd;
	char buff1[10][10] = {"hellow","i am fine","happy","sorry","bye"};
	char b1[10]="bye";
	char buffer[100];
	int newfd;
	int retval=0,i;
	int read_retval;
	char t;
	fopdata cdata;

	socketfd = socket (AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("failed to creat a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr,0,sizeof(mysockaddr));

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
	newfd = accept(socketfd, NULL, NULL);
	if(newfd==-1)
	{
		perror("accept system call failed \r \n");
		close(socketfd);
		exit(1);
	}
	printf("-->server :got the connection request from client  \r\n\n");

	for(i=0;i<10;i++)
	{
		sleep(2);
		
		read_retval = read(newfd, &cdata, sizeof(fopdata));
		
		if(read_retval == -1)
		{
			perror("read failed");
			exit(0);
		}
		printf("read_retval :%d\n", read_retval);

		rpcs_fop(&cdata);

		exit(1);

		printf("the data from the client : %s\n",buffer);

		t = strcmp(buffer,"bye");
		if(t == 0)
		{
			exit(0);
		}
		
		retval=write(newfd,&buff1[i],20);
		printf("server: buff1 write retval :%d\n",retval);
		
		if(retval == -1)
		{
			perror("write failed");
			exit(0);
		}

	}
	close(socketfd);
	return 0;
}
#if 0
int rpcc_send_data(fopdata *r)
{
	int retval = -1;

	retval = read(socketfd, r, sizeof(fopdata));

	return retval;
}
#endif

