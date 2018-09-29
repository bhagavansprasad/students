#include <stdio.h>
#include <unistd.h>
#include "rpc.h"
#include "errno.h"
#include <fcntl.h>
#include "rpcs1.h"

int process_client_request(fop_data_req *pcreq, fop_data_rep *preply)
{
	int fd = -1;
	printf("-->filename :%s\n", pcreq->data.odata.filename);
	printf("-->mode     :%d\n", pcreq->data.odata.mode);
	printf("-->flags    :%d\n", pcreq->data.odata.flags);

	if(pcreq->operation == OPEN_REQUEST)
	{
		fd = open(pcreq->data.odata.filename, pcreq->data.odata.mode, pcreq->data.odata.flags);

		preply->operation = OPEN_REPLY;

		if (fd < 0)
		{
			preply->sudata.sodata.error = errno;
			printf("server open errno = %d\n",preply->sudata.sodata.error);
		}

		preply->sudata.sodata.fd = fd;
		printf("server open fd is: %d\n",fd);
		return preply->sudata.sodata.fd;

	}

	else if(pcreq->operation == READ_REQUEST)
	{

		int r=read(pcreq->data.rdata.fd,preply->sudata.srdata.buff,
				pcreq->data.rdata.len);

		preply->operation = READ_REPLY;

		if(r< 0) 
		{
			preply->sudata.srdata.error = errno;
			printf("server read errno = %d\n",preply->sudata.srdata.error);
		}

		preply->sudata.srdata.retval = r;
		printf("server read retval is:%d\n",r);
		return preply->sudata.srdata.retval;
	}

	else if(pcreq->operation == WRITE_REQUEST)
	{

		int	w=write(pcreq->data.wdata.fd,pcreq->data.wdata.buff,pcreq->data.wdata.len);

		preply->operation = WRITE_REPLY;

		if(w<0)
		{
			preply->sudata.swdata.error = errno;
			printf("server write errno = %d\n",preply->sudata.srdata.error);
		}

		preply->sudata.swdata.retval = w;
		printf("server write retval is:%d\n",w);
		return preply->sudata.swdata.retval;

	}
	else if(pcreq->operation == LSEEK_REQUEST)
	{


		int l=lseek(pcreq->data.seekdata.fd,pcreq->data.seekdata.offset,pcreq->data.seekdata.whence);

		preply->operation = LSEEK_REPLY;

		if(l<0)
		{

			preply->sudata.sseekdata.error = errno;
			printf("server lseek errno = %d\n",preply->sudata.sseekdata.error);

		}
		preply->sudata.sseekdata.newoffset = l;
		printf("server lseek newoffset is:%d\n",l);
		return preply->sudata.sseekdata.newoffset;

	}

	else if(pcreq->operation == CLOSE_REQUEST)
	{
		int c=close(pcreq->data.cdata.fd);

		preply->operation = CLOSE_REPLY;
		if(c<0)
		{
			preply->sudata.scdata.error = errno;
			printf("server close errno = %d\n",preply->sudata.scdata.error);
		}
		preply->sudata.scdata.fd = c;
		printf("server close fd is:%d\n",c);
		return preply->sudata.scdata.fd;
		

	}
	return 0;
} 
