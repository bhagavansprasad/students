#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include "struct.h"
#include "structrep.h"

//int server_read_req(struct fds *a_fds );
int newsockfd = -1;
int tcp_server_init()
{
	int sockfd, retval;
	socklen_t addr_size;


	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("socket creation failed\n");
		exit(1);
	}
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);


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
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
//	close(sockfd);
}

int server_read_req(struct fds *a_fds )
{
	int rval;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	rval=read(newsockfd, a_fds, sizeof(struct fds));
	printf("read rval:%d\n",rval);

}
int server_reply_data(struct server *s)
{	
	int retval = 0;

	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	
	sdump_data_before_write(s);
	retval = write(newsockfd, s, sizeof(struct server));

	printf ("-->write retval :%d\n", retval);

	//return retval;
}
