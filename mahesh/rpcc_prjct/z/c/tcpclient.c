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



int sockfd = -1;
int tcp_client_init()
{
	struct sockaddr_in clientaddr;
	int retval;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientaddr.sin_port = htons(9999);
	if( connect(sockfd, (struct sockaddr *)&clientaddr, sizeof(clientaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}

	//close(sockfd);

	return 0;
}

int client_send_data(struct fds *a_fds)
{	
	int retval = 0;

	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("tcp Type: %d\n",a_fds->type);

	dump_data_before_write(a_fds);
	retval = write(sockfd, a_fds, sizeof(struct fds));

	printf ("-->write retval :%d\n", retval);

	return retval;
}
int client_read_req(struct server *s )
{
	int rval;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	rval=read(sockfd, s, sizeof(struct server));
	printf("read rval:%d\n",rval);
}
