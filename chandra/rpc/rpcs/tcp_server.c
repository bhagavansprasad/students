#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"fcntl.h"
#include"unistd.h"
#include"req_struct.h"
#include"reply_struct.h"

int server_socketfd = -1, newfd = -1;

void tcp_server_init(void)
{
	int newfd;
	int connected;    
	struct sockaddr_in mysockaddr;
	server_socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(server_socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(8000);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(server_socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed\r\n");
		close(server_socketfd);
		exit(1);
	}

	if(listen(server_socketfd, 5) == -1)
	{
		perror("listen system call failed\r\n");
		close(server_socketfd);
		exit(1);
	}

	printf("--->server : Going for accepting connection \r\n");
	newfd = accept(server_socketfd, NULL, NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(server_socketfd);
		exit(1);
	}

	printf("--->server : Got the connection request from client \r\n\n");

}

int server_read_data(struct rpcc *req)
{
	int rval;


	rval = read(newfd, req, sizeof(struct rpcc));

	printf("S. read rval is : %d\n", rval);
	return 0;
}

int server_write_data(struct rpcs *reply)
{
	int retval;


	retval = write(newfd, reply, sizeof(struct rpcs));

	printf("-->S. socket write retval :%d\n", retval);

	return 0;
}
//void close_socket()
//{
//	close(server_socketfd);
//}


