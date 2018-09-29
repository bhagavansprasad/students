#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "errno.h"
#include "string.h"
#include "sys/types.h"
main()
{
	int listedfd=0,connfd=0;
	struct sockaddr_in serv_addr;
	
	char sendbuff[1025];
	int numrv;
	
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	printf("socket retrieve success\n");
	
	memset(&serv_addr,0,sizeof(serv_addr));
	memset(sendbuff,0,sizeof(sendbuff));
	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=hton1(INADDR_ANY);
	serv_addr.sin_port=htons(5000);

	bind(listenfd,())
}
