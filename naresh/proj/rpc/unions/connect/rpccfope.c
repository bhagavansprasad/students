#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"

int rpcc_fope(fopdata *r)
{
	int k,rd,w,t,f,offset,whence,rfd;

	printf("------%d\n",r->fope);

	switch(r->fope)
	{
		case 1:
			k = open(r->das.odata.fname, r->das.odata.mode, r->das.odata.flags);
			printf("file name is : %s\n",r->das.odata.fname);			
			printf("fd is : %d\n",k);
			return k;
			break;
		case 2:
			rd = read(r->das.rdata.rfd, r->das.rdata.rbuff, r->das.rdata.len);
			printf("return fd: %d\n",rd);
       		printf("-->%s\n",r->das.rdata.rbuff);
			return rd;
			break;
		case 3:
			w = write(r->das.wdata.wfd, r->das.wdata.wbuff, r->das.wdata.len);
			return w;
			break;
		case 4:
			printf("-->in final offset :%d\n", offset);
			printf("-->in final whence :%d\n", whence);
			t = lseek(r->das.sdata.rfd, r->das.sdata.offset, r->das.sdata.whence);
			return t;
			break;
		case 5:
			f = close(r->das.cdata.fd);
			return f;
			break;
		default:
			printf("there is no elements");
			break;
	}
}
