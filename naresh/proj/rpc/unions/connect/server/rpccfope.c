#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "errno.h"
#include "arpc.h"
#include "rpcs.h"

int process_client_request(fopdata_req *pcreq, fopdata_rep *preply)
{
	//	int rd, w, l, t, offset, whence;
	int fd = -1;
	//printf("------%d\n",pcreq->fope);

	printf("-->fname :%s\n", pcreq->das.odata.fname);
	printf("-->mode :%d\n",  pcreq->das.odata.mode);
	printf("-->flags :%d\n", pcreq->das.odata.flags);

	//	return 0;
	switch(pcreq->fope)
	{
		case OPEN_REQUEST:
			fd = open(pcreq->das.odata.fname, pcreq->das.odata.mode, pcreq->das.odata.flags);
			printf("file name is : %s\n",pcreq->das.odata.fname);
			preply->fope = OPEN_REPLY;
			if(fd < 0)
			{
				preply->sdas.sodata.erno = errno;
				printf("server open errno = %d\n",preply->sdas.sodata.erno);
				perror("open failed because ");
				return 	preply->sdas.sodata.erno; 
			}
			preply->sdas.sodata.fd = fd;
			printf("server open fd value = %d\n",preply->sdas.sodata.fd);
			return 	preply->sdas.sodata.fd;

		case READ_REQUEST:
			printf("READ OPER");
			rd = read(pcreq->das.rdata.rfd, pcreq->das.rdata.rbuff, pcreq->das.rdata.len);
			printf("return fd: %d\n",rd);

			preply->fope = READ_REPLY;
			preply->sdas.srdata.rd = rd;
			strcpy(preply->sdas.srdata.rbuff, preply->sdas.srdta.rbuff);
			printf("server read retval = %d\n",preply->sdas.srdata.retval);
			printf("server buff =%s\n",preply->sdas.srdata.rbuff); 
			
			if(preply->sdas.srdata.erno < 0)
			{
				preply->sdas.srdata.erno = errno;
				printf("server read errno = %d\n",preply->sdas.srdata.erno);
				perror("read failed because");
				return preply->sdas.srdata.erno; 
			}
			printf("-->%s\n",pcreq->das.rdata.rbuff);
			printf("server read fd value = %d\n",preply->sdas.srdata.erno);
			return preply->sdas.srdata.erno;
			break;

		case WRITE_REQUEST:
			printf("WRITE OPER\n");
			w = write(pcreq->das.wdata.wfd, pcreq->das.wdata.wbuff, pcreq->das.wdata.rd);
			preply->fope = WRITE_REPLY;
			preply->sdas.swdata.wfd = w;

			printf("server write retval = %d\n",preply->sdas.swdata.wfd);
			if(preply->sdas.srdata.wfd < 0)
			{
				preply->sdas.swdata.erno = errno;
				printf("server write errno :%d\n",preply->sdas.swdata.erno);
				return preply->sdas.swdata.erno;
			}
			return preply->sdas.swdata.wfd;
			break;

		case LSEEK_REQUEST:
			printf("LSEEK OPER\n");

			printf("-->in final offset :%d\n", offset);
			printf("-->in final whence :%d\n", whence);
			l = lseek(pcreq->das.sdata.rfd, pcreq->das.sdata.offset, pcreq->das.sdata.whence);
			preply->sdas.sldata.offset = l;
			printf("server lseek retval :%d\n",preply->sdas.sldata.offset);
			if(preply->sdas.sldata.offset < 0)
			{
				preply->sdas.sldata.erno = errno;
				printf("server lseek retval :%d\n",preply->sdas.sldata.erno);
				return preply->sdas.sldata.erno;
			}
			return preply->sdas.sldata.erno;
			break;

		case CLOSE_REQUEST:
			printf("CLOSE OPER\n");
			t = close(pcreq->das.cdata.fd);
			preply->sdas.scdata.fd = t;
			if(preply->sdas.scdata.fd < 0)
			{
				preply->sdas.scdata.erno = errno;
				printf("server close errno :%d\n",preply->sdas.scdata.erno);
				return preply->sdas.scdata.erno; 
			}
			return preply->sdas.scdata.erno;
			break;

		default:
			printf("there is no elements");
			break;
	}
	return 0;
}
