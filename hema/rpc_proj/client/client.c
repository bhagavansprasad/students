#include<stdio.h>
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "rpc_op.h"


int sockfd = -1;
int c_rpc_send_request(fope_struct *pfdata)
{
	int wretval = 0;

	wretval = write(sockfd, pfdata, sizeof(fope_struct));

	printf("-->C:write retval :%d\n", wretval);

	return wretval;
}

int c_rpc_read_reply(fope_struct_reply *preply)
{
	int rretval = 0;

	rretval = read(sockfd, preply, sizeof(fope_struct_reply));

	printf("-->C: read retval       :%d\n", rretval);

	return rretval;
}


init_rpc_communication()
{
	struct sockaddr_in myclientaddr;
	char request[] = "how are you";
	char reply[100];

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port=htons(8000);

	printf("-->client:connecting to the server\n");
	connect(sockfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));

	//c_send_request(sockfd, request);
	//c_read_reply(sockfd, reply);

	printf("-->C: got the reply from server :%s\n", reply);
}

