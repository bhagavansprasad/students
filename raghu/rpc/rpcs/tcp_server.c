#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include "rpc_fp.h"
#include "rpc_req.h"
int socketfd = -1;
int newfd = -1;
void tcp_server()
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
	mysockaddr.sin_port = htons(9999);
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

int server_read(struct rpcc *data)
{

	int read_retval;
	read_retval = read(newfd, data, sizeof(struct rpcc));
//	debug_after_read(data);
	printf("server read_retval =%d\n",read_retval);
	return 0;
}

int server_write(struct reply_final *srf)
{
	int wr_retval;
	wr_retval = write(newfd, srf, sizeof(struct reply_final));
	printf("server write_retval: %d\n",wr_retval);
	return 0;

}
