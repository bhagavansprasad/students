#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"struct_req.h"
#include"struct_replay.h"

int socketfd=-1, newfd;

void tcp_server_init(void)
{
	printf("%d %s \n ",__LINE__,__FILE__);

	int connected;    
	struct sockaddr_in mysockaddr;
	socketfd = socket(AF_INET, SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("failed to  create a socket \r\n");
		exit(1);
	}

	memset(&mysockaddr, 0, sizeof(mysockaddr));

	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(10000);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(socketfd, (struct sockaddr *)&mysockaddr, sizeof(mysockaddr)) == -1)
	{
		perror("bind system call failed");
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
	newfd = accept(socketfd, NULL, NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\r\n");
		close(socketfd);
		exit(1);
	}

	printf("--->server : Got the connection request from client \r\n\n");

}

int server_read_data(struct final *c_req)
{
	int retval;

	printf("%d %s \n ",__LINE__,__FILE__);

	retval = read(newfd, c_req, sizeof(struct final));

	printf("-->S. socket read retval :%d\n", retval);

	return retval;
}

int server_write_data(struct S_final *preply)
{
	int retval;

	printf("%d %s \n ",__LINE__,__FILE__);

	retval = write(newfd, preply, sizeof(struct S_final));

	printf("-->S. socket write retval :%d\n", retval);

	return retval;
}
void close_socket()
{
	close(socketfd);
}
