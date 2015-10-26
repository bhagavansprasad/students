#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"unistd.h"
#include "error.h"
#include "stdlib.h" 
#include "struct_client.h"
#include <fcntl.h>

int socketfd = -1;

init_rpcc_network_comm(int port, char * srvr_ip)
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
	myclientaddr.sin_addr.s_addr = inet_addr("192.168.1.36");
	myclientaddr.sin_port = htons(8888);
	
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


int rpcc_send_req(struct fop_data_t *fop_data)
{
	int retval = -1;

	retval =  write(socketfd, fop_data, sizeof(struct fop_data_t));

	return retval;
}
