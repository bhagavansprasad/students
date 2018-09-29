#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "define.h"
#include "comm_init.h"

int rpc_send_request(fop_data *datac)
{	
	int fd = get_comm_id();
	int retval = 0;

	printf("size of fop_data :%u\n", sizeof(fop_data));

	if( (retval = send(fd, (char*)datac, sizeof(fop_data) , 0)) < 0)
	{
		perror("Send failed");
		printf("Send failed retval :%d\n", retval);
		return 1;
	}

	printf("Send success retval :%d\n", retval);

	return retval;
}

int rpc_recv_reply(fop_data *reply)
{	
	int fd = get_comm_id();
	int retval = 0;

	if( (retval = recv(fd, (char*)reply, sizeof(fop_data) , 0)) < 0)
	{
		printf("Recv failed retval :%d\n", retval);
		return 1;
	}

	printf("Recv success retval :%d\n", retval);

	return retval;
}

