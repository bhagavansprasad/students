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
#include "arpc.h"
#include "nets.h"

int socketfd = -1;
int newfd = -1;

int init_net_comm(int port)
{
	struct sockaddr_in mysockaddr;
	socketfd = socket (AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1)
	{
		perror("failed to creat a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr,0,sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_addr.s_addr = INADDR_ANY;
	mysockaddr.sin_port = htons(port);

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
	
	return socketfd;
}
int read_from_client(fopdata_req *pcreq)
{
	int read_retval;

	read_retval = read(newfd, pcreq,sizeof(fopdata_req));

	printf("server read_retval = %d\n",read_retval);

	return read_retval;

}
int write_to_client(fopdata_rep *preply)
{
	int retval = -1;

	retval = write(newfd, preply, sizeof(fopdata_rep));
	printf("server write retval :%d\n",retval);

	return retval;
}

int close_net_communication(void)
{
	close(newfd);
	close(socketfd);

	return 0;
}
