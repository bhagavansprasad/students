#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "server_client.h"
//#include "rpc_req.h"
int socketfd = -1;
int newfd = -1;
void server_comm()
{
	struct sockaddr_in mysockaddr;
	int retval = 0;
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(6666);
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
}

int server_read(struct fop_data_t *fop_data)
{

	int read_retval;
	read_retval = read(newfd, fop_data, sizeof(struct fop_data_t));
	printf("server read_retval =%d\n",read_retval);
	return 0;
}


