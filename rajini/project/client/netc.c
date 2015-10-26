#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"unistd.h"
#include "error.h"
#include "stdlib.h" 
#include "rpc.h"
#include <fcntl.h>

int socketfd = -1;

int init_netc_communication(char *srvr_ip, int srvr_port)
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
	myclientaddr.sin_port = htons(srvr_port);

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

int rpcc_send_data(fop_data_req *preq)
{
	int retval= -1;

	printf("-->In %s function the data\n", __FUNCTION__);
	printf("-->file :%s\n", preq->data.odata.filename);
	printf("-->mode :%d\n", preq->data.odata.mode);
	printf("-->flags:%d\n", preq->data.odata.flags);

	retval = write(socketfd, preq,sizeof(fop_data_req));

	printf("retval ===\n");
	return retval;
}

int write_to_server(fop_data_req *pcreq)
{
	int write_retval = -1;

	write_retval =  write(socketfd, pcreq, sizeof(fop_data_req));
	printf("client write_retval = %d\n", write_retval);

	return write_retval;
}

int read_from_server(fop_data_rep *psreply)
{
	int read_retval;

	read_retval=read(socketfd, psreply, sizeof(fop_data_rep));

	printf("client read_retval = %d\n", read_retval);

	return read_retval;

}

int close_netc_communication(void)
{
	close(socketfd);

	return 0;
}
