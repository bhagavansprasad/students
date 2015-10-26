#include "stdio.h"
#include "fcntl.h"
#include "errno.h"
#include <rpc.h>
#include "rpcs3.h"

int process_client_request(fop_data_req *pcreq, fop_data_rep *preply)
{
	//int k,rd,w,t,f,offset,whence,rfd;
	int fd = -1;


	printf("-->filename :%s\n", pcreq->data.odata.filename);
	printf("-->mode     :%d\n", pcreq->data.odata.mode);
	printf("-->flags    :%d\n", pcreq->data.odata.flags);

	return 0;
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
#if 0
		case 2:
			rd = read(pcreq->das.rdata.rfd, pcreq->das.rdata.rbuff, pcreq->das.rdata.len);
			printf("return fd: %d\n",rd);
       		printf("-->%s\n",pcreq->das.rdata.rbuff);
			return rd;
			break;
		case 3:
			w = write(pcreq->das.wdata.wfd, pcreq->das.wdata.wbuff, pcreq->das.wdata.len);
			return w;
			break;
		case 4:
			printf("-->in final offset :%d\n", offset);
			printf("-->in final whence :%d\n", whence);
			t = lseek(pcreq->das.sdata.rfd, pcreq->das.sdata.offset, pcreq->das.sdata.whence);
			return t;
			break;
		case 5:
			f = close(pcreq->das.cdata.fd);
			return f;
			break;
#endif
		default:
			printf("there is no elements");
			break;
	}
}
