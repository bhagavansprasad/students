#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "rpc.h"

int socketfd = -1;
int newfd = -1;

int init_nets_communication(int srvr_port)
{
	struct sockaddr_in mysockaddr;
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(srvr_port);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	if(listen(socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(socketfd,NULL,NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Got the connection request from client \r\n\n");

	return socketfd;
}

int read_from_client(fop_data_req *pcreq)
{

	int read_retval;

	read_retval = read(newfd, pcreq, sizeof(fop_data_req));

	printf("server read_retval =%d\n", read_retval);

	return read_retval;
}

int write_to_client(fop_data_rep *psreply)
{
	int retval = -1;

	retval = write(newfd, psreply, sizeof(fop_data_rep));

	return retval;
}

int close_nets_communication(void)
{
	close(newfd);
	close(socketfd);

	return 0;
}
