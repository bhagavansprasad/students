#include<stdio.h>
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int socketfd = -1;
int c_send_request(int sockfd, char *request)
{
	int wretval = 0;

	wretval = write(sockfd, request, strlen(request));

	printf("-->C:write retval :%d\n",wretval);

	return wretval;
}

int c_read_reply(int sockfd, char *reply)
{
	int rretval = 0;

	rretval = read(sockfd, reply, 100);

	reply[rretval]='\0';
	printf("-->C: read retval       :%d\n", rretval);

	return rretval;
}


int main()
{
	struct sockaddr_in myclientaddr;
	char request[] = "how are you";
	char reply[100];

	socketfd = socket(AF_INET,SOCK_STREAM,0);

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port=htons(8000);

	printf("-->client:connecting to the server\n");
	connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));

	c_send_request(socketfd, request);
	c_read_reply(socketfd, reply);

	printf("-->C: got the reply from server :%s\n", reply);
}

