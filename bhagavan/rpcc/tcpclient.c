#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include "s.h"

int sockfd = -1;
int tcp_client_init()
{
	struct sockaddr_in clientaddr;
	char sbuf[200]="how are you server";
	int retval;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientaddr.sin_port = htons(9999);
	if( connect(sockfd, (struct sockaddr *)&clientaddr, sizeof(clientaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}

#if 0
	retval = write(sockfd, sbuf, strlen(sbuf));
	printf("retval=%d message=%s\n", retval, sbuf);

	sleep(5);

	close(sockfd);
#endif

	return 0;
}

int client_send_data(struct my_struct *pdata)
{
	return write(sockfd, pdata, sizeof(struct my_struct));
}
