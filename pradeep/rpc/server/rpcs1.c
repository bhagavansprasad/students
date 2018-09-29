#include <stdio.h>
#include <unistd.h>
#include "rpc.h"
#include "errno.h"
#include <fcntl.h>
#include "rpcs1.h"
#include <string.h>

int process_client_request(fop_data_req *pcreq, fop_data_rep *sreply)
{
	int fd = -1;

	if(pcreq->operation == OPEN_REQUEST)
	{
		fd = open(pcreq->data.odata.filename, pcreq->data.odata.mode, pcreq->data.odata.flags);

		sreply->operation = OPEN_REPLY;

		if (fd < 0)
		{
			sreply->sudata.sodata.error = errno;
			printf("server open error no : %d\n",sreply->sudata.sodata.error);
			perror("open failed because:");
			return sreply->sudata.sodata.error;
		}	
		sreply->sudata.sodata.fd = fd;

		printf("server side open fd is: %d\n",sreply->sudata.sodata.fd);

		return sreply->sudata.sodata.fd;

	}

	else if(pcreq->operation == READ_REQUEST)
	{
		int r=0;


		r=read(pcreq->data.rdata.fd,pcreq->data.rdata.buff, pcreq->data.rdata.len);

		sreply->sudata.srdata.retval=r;
		pcreq->data.rdata.buff[sreply->sudata.srdata.retval] = '\0';
		strcpy(sreply->sudata.srdata.buff, pcreq->data.rdata.buff);

		if(r<0)
		{
			printf("error no : %d\n",sreply->sudata.srdata.error);
			perror("read failed beacuse :");
			return sreply->sudata.srdata.error;
		}
		printf("server side read retval = %d\n",sreply->sudata.srdata.retval);
		printf("server side read buff   = %s\n",sreply->sudata.srdata.buff);

		return sreply->sudata.srdata.retval;

	}

	else if(pcreq->operation == WRITE_REQUEST)
	{
		int w=0;


		w=write(pcreq->data.wdata.fd, pcreq->data.wdata.buff, pcreq->data.wdata.len);

		sreply->sudata.swdata.retval=w;

		if(w<0)
		{
			sreply->sudata.swdata.error = errno;
			printf("server write error no : %d\n",sreply->sudata.swdata.error);
			perror("write failed because :");
			return sreply->sudata.swdata.error;
		}
		printf("server write retval = %d\n",sreply->sudata.swdata.retval);

		return sreply->sudata.swdata.retval;
	}

	else if(pcreq->operation == LSEEK_REQUEST)
	{
		int l=0;


		l=lseek(pcreq->data.seekdata.fd, pcreq->data.seekdata.offset, pcreq->data.seekdata.whence);
		sreply->sudata.sseekdata.newoffset = l;

		if(l<0)
		{
			printf("error no : %d\n",sreply->sudata.sseekdata.error);
			perror("lseek failed because :");
			return sreply->sudata.sseekdata.error;
		}

		printf("server lseek retval = %d\n",sreply->sudata.sseekdata.newoffset);
		return sreply->sudata.sseekdata.newoffset;
	}

	else if(pcreq->operation == CLOSE_REQUEST)
	{
		int c=0;

		c=close(pcreq->data.cdata.fd);
		sreply->sudata.scdata.fd=c;

		if(c<0)
		{

			printf("error no : %d\n",sreply->sudata.scdata.error);
			perror("close failed beacuse :");

			return sreply->sudata.scdata.error;
		}
		printf("server close retval = %d\n",sreply->sudata.scdata.fd);
		return sreply->sudata.scdata.fd;
	}

	return 0;
}
