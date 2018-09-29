#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"unistd.h"
#include "error.h"
#include "stdlib.h" 
#include "arpc.h"
#include <fcntl.h>

int socketfd = -1;

int init_rpcc_network_comm(int port, char *srvr_ip)
{
	
	int connected;
	struct sockaddr_in myclientaddr;
	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd == -1)
	{
		perror("--->client:failed to creat a socket \n");
		exit(1);
	}
	
	myclientaddr.sin_family = AF_INET;
	myclientaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	myclientaddr.sin_port = htons(port);
	
	printf("----->client: connecting to the server \n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr,sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("--->client: connect system call failed \n");
		close(socketfd);
		exit(1);
	}

	return socketfd;
}

int rpcc_send_req(fop_data_req *pcdata)
{
	int retval = -1;

	retval =  write(socketfd, pcdata, sizeof(fop_data_req));

	return retval;
}
#if 0
int rpcc_recv_data(fop_data_rep server_data)
{
	int read_retval;

	read_retval=read(socketfd, &server_data ,sizeof(fop_data_rep));
	
	printf("client read_retval = %d\n",read_retval);

	return read_retval;

}
#endif
