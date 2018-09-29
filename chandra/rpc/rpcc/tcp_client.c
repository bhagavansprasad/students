#include <stdio.h>
#include "req_struct.h"
#include "reply_struct.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int debug_before_write(struct rpcc *);

int client_socketfd = -1;

int tcp_client_init(void)
{

	int connected;
	struct sockaddr_in myclientaddr;
	//int retval = 0;
	client_socketfd = socket(AF_INET,SOCK_STREAM,0);
	if(client_socketfd == -1)
	{
		perror("--->client:failed to creat a socket \n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.30");
	myclientaddr.sin_port = htons(8000);
	printf("----->client: connecting to the server \n");
	connected = connect(client_socketfd, (struct sockaddr *)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed \n");
		close(client_socketfd);
		exit(1);
	}
	return 0;
}

int client_send_req(struct rpcc *req)
{
//	debug_before_write(req);
	int retval = 0;
	retval = write(client_socketfd, req, sizeof(struct rpcc));

	printf("C. write socket retval : %d\n", retval);
	return retval;
}

int client_read_req(struct rpcs *reply)
{
	int retval = 0;

	retval = read(client_socketfd, reply, sizeof(struct rpcs));

	printf("C. read socket retval : %d\n", retval);
	return retval;

}

