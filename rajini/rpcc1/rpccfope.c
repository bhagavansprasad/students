#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"

int rpcc_fope(int fope, union all_data *das)
{
	int k,r,w,t,f,offset,whence,rfd;
	switch(fope)
	{
		case 1:
			k = open(das->odata.fname, das->odata.mode, das->odata.flags);
			printf("file name is : %s\n",das->odata.fname);			
			printf("fd is : %d\n",k);
			return k;
			break;
		case 2:
			r = read(das->rdata.rfd, das->rdata.rbuff, das->rdata.len);
			printf("return fd: %d\n",r);
       		printf("-->%s\n",das->rdata.rbuff);
			return r;
			break;
		case 3:
			w = write(das->wdata.wfd, das->wdata.wbuff, das->wdata.len);
			return w;
			break;
		case 4:
			printf("-->in final offset :%d\n", offset);
			printf("-->in final whence :%d\n", whence);
			t = lseek(das->sdata.rfd, das->sdata.offset, das->sdata.whence);
			return t;
			break;
		case 5:
			f = close(das->cdata.fd);
			return f;
			break;
		default:
			printf("there is no elements");
			break;
	}
}
