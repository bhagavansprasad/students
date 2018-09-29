#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "../defs/rpc_fop.h"

char srvr_ip[] = "127.0.0.1";
int srvr_port = 9090;
int i;

int main()
{
	int newSocket = -1;
	int retval = 0;
	int reply_retval = 0;
	int server_sock_fd = -1;
	struct rpc_fop_data rpcdata;
	struct rpc_fop_data_reply reply;

	printf("-->S. IN %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	server_sock_fd = init_server_connection(srvr_ip, srvr_port);

	for ( ; ;)
	{
		newSocket = accept_new_client_request(server_sock_fd);

		if(newSocket == -1)
		{

			perror("accept system call failed\n");
			close(server_sock_fd);

			exit(1);
		}

		for (i = 0 ; i < 9  ; i++)
		{
			recv_rpcc_server_request(newSocket, &rpcdata, sizeof(rpcdata));

			retval = rpc_foperations(&rpcdata, &reply);

			printf("-->S. rpc_foperations retval :%d\n", retval); 

			reply_retval =  send_rpcc_server_reply(newSocket, &reply, sizeof(reply));
			
			printf("-->S. rpc_foperations reply_retval :%d\n", reply_retval); 
			
			sleep(1);
		}
		exit(0);
		sleep(1);
	}
}

int recv_rpcc_server_request(int sock_fd, void *pdata, int len)
{
	int retval = -1;

	printf("-->S. IN %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	retval = recv(sock_fd, pdata, len, 0);

	printf("-->S: IN receive retval :%d\n", retval);

	return retval;
}

int send_rpcc_server_reply(int sock_fd, void *pdata, int len)
{
	int reply_retval = -1;

	printf("-->S. IN %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	reply_retval = send(sock_fd, pdata, len, 0);

	printf("-->S: send retval :%d\n", reply_retval);

	return reply_retval;
}

int accept_new_client_request(int server_sock_fd)
{
	int newsockfd = -1;
	struct sockaddr_in serverAddr;

	printf("-->S. IN %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	socklen_t addr_size = sizeof serverAddr;

	newsockfd = accept(server_sock_fd, (struct sockaddr *)&serverAddr, &addr_size);

	printf("-->S. after accept newsockfd :%d\n", newsockfd);

	return newsockfd;
}

int init_server_connection(char *srvr_addr, int port)
{
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	int server_sock_fd;

	printf("-->S. IN %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	server_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	printf("-->S. socketfd :%d\n", server_sock_fd);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(srvr_addr);
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); 

	bind(server_sock_fd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(listen(server_sock_fd , 5) == 0)
		printf("-->S. Listening\n");
	else
		printf("-->S. Error\n");

	printf("-->S. before return from :%s socketfd :%d\n", __FUNCTION__, server_sock_fd);

	return server_sock_fd;
}
