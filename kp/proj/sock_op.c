#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include"define.h"
int fd;
int send_sock_req(fop_data datac)
{	
	int sock;
	init_sock(sock);
	while(1)
	{
		if( send(sock ,(char*)&datac, sizeof(fop_data) , 0) < 0)
		{
		printf("Send failed");
			return 1;
		}
	printf("%d\n",fd);
	}
}
//int

