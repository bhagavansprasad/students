#include<stdio.h>
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int socketfd = -1;
int s_read_request(int sockfd, char *request)
{
	int rretval = 0;

	rretval = read(sockfd, request, 100);

	printf("-->S:read retval :%d\n", rretval);

	return rretval;
}

int s_send_reply(int sockfd, char *reply)
{
	int wretval = 0;

	wretval = write(sockfd, reply, strlen(reply));

	printf("-->S: write retval  :%d\n", wretval);

	return wretval;
}


int main()
{
	int socketfd, newfd;
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

	printf("-->S: got the connection request\n");

	s_read_request(newfd, request);
	printf("-->S: Client's' request  :%s\n", request);
	s_send_reply(newfd, reply);

	return 0;
}
