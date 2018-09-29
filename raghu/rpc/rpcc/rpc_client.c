#include <stdio.h>
#include "rpc_req.h"
#include "rpcc_fp.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/i:n.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int socketfd = -1;

int tcp_client_init(void)
{
	
	int connected;
	struct sockaddr_in myclientaddr;
	int retval=0;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("--->client:failed to creat a socket \n");
		exit(1);
	}
	
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	myclientaddr.sin_port = htons(6666);
	printf("----->client: connecting to the server \n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed \n");
		close(socketfd);
		exit(1);
	}
	return 0;
}
void client_write_data(struct rpcc *data, struct reply_final *srf)
{
	int wrt_retval;
	wrt_retval=write(socketfd,data,sizeof(struct rpcc));
	return wrt_retval;
	printf("wrt_retval = %d",wrt_retval);
}
