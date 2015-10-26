#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include "s.h"

int newsockfd = -1;
int tcp_server_init()
{
	int sockfd, retval;
	socklen_t addr_size;
	char rbuff[200];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("socket creation failed\n");
		exit(1);
	}

	struct sockaddr_in myserveraddr,clientaddr;

	myserveraddr.sin_family=AF_INET;
	myserveraddr.sin_port=htons(9999);
	myserveraddr.sin_addr.s_addr= INADDR_ANY;

	if(bind(sockfd,(struct sockaddr *)&myserveraddr, sizeof(myserveraddr))<0)
	{
		perror("bind");
		return -1;
	}

	listen(sockfd, 5);
	addr_size=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr *)&clientaddr, &addr_size);

#if 0
	retval=read(newsockfd, rbuff, 100);
	rbuff[retval] = '\0';
	printf("recv buff = %s\n", rbuff);
	close(sockfd);
	close(newsockfd);
#endif
}

int server_read_data(struct my_struct *pdata )
{
	read(newsockfd, pdata, sizeof(struct my_struct));
}
