#include <stdio.h>
#include "/home/bhagavan/students/sudharshan/nrpc/inc/define.h"
#include "switchs.h"
#include <fcntl.h>
int main(int argc , char *argv[])
{
	//fop_data reply;
	int retval;
	fop_data datac;
	fop_data reply;

	// init_server_comm();
	init_communication_channel_server(SRVR_PORT);

	while(rpc_recv_data(&datac) > 0 )
	{
		printf ("recv retval :%d\n", retval);
		switch(datac.cmd)
		{
			case FILE_OPEN:
				retval = aopen(datac.udata.opn.fname, datac.udata.opn.mode);

				datac.udata.opn.fd = retval;
				printf("srvr open fd :%d\n", datac.udata.opn.fd);

				//	return retval;
				rpc_send_reply(&datac);
				break;

			case FILE_READ:
				retval = aread( datac.udata.rdwt.fd, reply.udata.rdwt.buffer,
						datac.udata.rdwt.count);

				reply.udata.rdwt.count = retval;
				printf("srvr read fd :%d \n",datac.udata.rdwt.fd);
				printf("read buffer : %s\n", reply.udata.rdwt.buffer);
				printf("srvr read count:%d\n",datac.udata.rdwt.count);
				rpc_send_reply(&reply);

				break;
				//return retval;


			case FILE_WRITE:
				retval = awrite( datac.udata.rdwt.fd, datac.udata.rdwt.buffer,
						datac.udata.rdwt.count);

				datac.udata.rdwt.count = retval;

			printf("srvr write fd :%d \n",datac.udata.rdwt.fd);
				printf("write buffer : %s\n", datac.udata.rdwt.buffer);
				printf("srvr write count:%d\n",datac.udata.rdwt.count);
				rpc_send_reply(&datac);
				break;
				//return retval;


			case FILE_SEEK:
				retval = alseek(datac.udata.seek.fd, datac.udata.seek.offset,
						datac.udata.seek.whence);

				datac.udata.seek.offset=retval;
				printf("srvr seek fd:%d\n",datac.udata.seek.fd);
				printf("srvr seek offset :%d \n",datac.udata.seek.offset);
				rpc_send_reply(&datac);

				break;
				//return retval;

			case FILE_CLOSE:
				aclose(datac.udata.cls.fd);
				rpc_send_reply(&datac);

				break;

			default:
				printf("-->%s, %s, %d ***PANIC*** Received Invalid command :%d\n", 
						__FILE__, __FUNCTION__, __LINE__, datac.cmd);
				// exit(1);

		}
	}

	if(retval == 0)
	{
		printf("Client disconnected");
		fflush(stdout);
	}
	else if(retval == -1)
	{
		perror("recv failed");
	}

	return 0;
}

