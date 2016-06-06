#include<stdio.h>
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "rpc_op.h"

int newfd = -1;
int s_read_request(fope_struct *prequest)
{
	int rretval = 0;

	rretval = read(newfd, prequest, sizeof(fope_struct));

	printf("-->S:read retval :%d\n", rretval);

	return rretval;
}

int s_send_reply(fope_struct_reply *preply)
{
	int wretval = 0;

	wretval = write(newfd, preply, sizeof(fope_struct_reply));

	printf("-->S: write retval  :%d\n", wretval);

	return wretval;
}

int init_rpc_server()
{
	int socketfd;
	struct sockaddr_in mysockaddr;
	char reply[] = "I am fine";
	char request[100];

	socketfd=socket(AF_INET,SOCK_STREAM,0);

	memset(&mysockaddr, 0 ,sizeof(mysockaddr));
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port=htons(8000);
	mysockaddr.sin_addr.s_addr = INADDR_ANY;

	bind(socketfd ,(struct sockaddr *)&mysockaddr,sizeof(mysockaddr));

	listen(socketfd, 5);

	printf("-->S: going to accepting...\n");
	newfd = accept(socketfd, NULL, NULL);
	if(newfd == -1)
	{
		perror("accept system call failed\n");
		close(socketfd);
		exit(1);
	}

#if 0
	printf("-->S: got the connection request\n");
	s_read_request(newfd, request);
	printf("-->S: Client's' request  :%s\n", request);
	s_send_reply(newfd, reply);
#endif

	return 0;
}

int main()
{
	fope_struct request;
	fope_struct_reply reply;

	init_rpc_server();

	s_read_request(&request);
	s_rpc_fop(&request, &reply);
	s_send_reply(&reply);
}
