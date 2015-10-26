#include "stdio.h"
#include "fcntl.h"
#include <unistd.h>
#include "errno.h"
#include <rpc.h>
#include "rpcs3.h"

int process_client_request(fop_data_req *pcreq, fop_data_rep *preply)
{
	int retval;
	int fd = -1;

	printf("-->filename :%s\n", pcreq->data.odata.filename);
	printf("-->mode     :%d\n", pcreq->data.odata.mode);
	printf("-->flags    :%d\n", pcreq->data.odata.flags);

	switch(pcreq->operation)
	{
		case OPEN_REQUEST:
			fd = open(pcreq->data.odata.filename, pcreq->data.odata.mode, pcreq->data.odata.flags);
			preply->operation = OPEN_REPLY;
			preply->sudata.sodata.fd = OPEN_REPLY;

			if (fd < 0)
				preply->sudata.sodata.error = errno;

			printf("fd is :%d\n", fd);
			break;

		case READ_REQUEST:
			retval = read(pcreq->data.rdata.fd, preply->sudata.srdata.buff, pcreq->data.rdata.len);
			printf("return fd: %d\n", retval);
			break;

		case WRITE_REQUEST:
			retval = write(pcreq->data.wdata.fd, pcreq->data.wdata.buff,pcreq->data.wdata.len);
			break;

		case LSEEK_REQUEST:
			printf("-->in final whence :%d\n", pcreq->data.sdata.whence);
			retval = lseek(pcreq->data.sdata.fd, pcreq->data.sdata.offset, pcreq->data.sdata.whence);
			preply->sudata.sseekdata.newoffset = retval;
			printf("-->in final offset :%d\n", preply->sudata.sseekdata.newoffset);
			break;

		case CLOSE_REQUEST:
			retval = close(pcreq->data.cdata.fd);
			break;

		default:
			printf("there is no elements");
			break;
	}

	return retval;
}
