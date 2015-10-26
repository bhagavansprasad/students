#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "arpc.h"
int socketfd = -1;
int newfd = -1;

int server_comm(int port)
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
	mysockaddr.sin_port = htons(port);
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

int rpcs_recv_data(fop_data_req *pcdata)
{

	int read_retval;

	read_retval = read(newfd, pcdata, sizeof(fop_data_req));

	printf("server read_retval =%d\n", read_retval);

	return read_retval;
}
#if 0
int rpcs_send_req(fop_data_rep *server_data)
{
	int retval = -1;

	retval = write(newfd, server_data, sizeof(fop_data_rep));

	return retval;
}
#endif
