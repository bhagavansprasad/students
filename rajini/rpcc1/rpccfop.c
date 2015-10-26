#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"
#include "rpccfope.h"
#include "string.h"
#define OPEN_REQ 1
#define READ_REQ 2
#define WRITE_REQ 3
#define CLOSE_REQ 5
#define LSEEK_REQ 4
int rpccopen(char *fname, int mode, int flags)
{
	int fd;
	union all_data das;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fname :%s, flags :%d, mode :%d\n", fname, flags, mode);

	strcpy(das.odata.fname, fname);  
	das.odata.mode = mode;
	das.odata.flags = flags;

	fd=rpcc_fope(OPEN_REQ, &das);
	
	printf("-->return fd :%d\n", fd);

	return fd;
}

int rpccread(int rfd,char *buff,int len)
{
	int r;
	union all_data das;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("--> fd :%d, len :%d\n", rfd, len);
	
	printf(" Rbuff value :%s\n",buff);

	strcpy(das.rdata.rbuff,buff);
	das.rdata.rfd=rfd;
	das.rdata.len=len;

	r=rpcc_fope(READ_REQ, &das);
	strcpy(buff,das.rdata.rbuff);

	
	printf("in rpccfop buff is : %s\n",das.rdata.rbuff);
	printf ("----r value :%d\n",r);
	return r;
}

int rpccwrite(int wfd,char *wbuff,int len)
{
	int w;
	union all_data das;
	
	strcpy(das.wdata.wbuff,wbuff);
	das.wdata.wfd=wfd;
	das.wdata.len=len;

	w=rpcc_fope(WRITE_REQ, &das);

	return w;
}

off_t rpcclseek(int rfd, off_t offset, int whence)
{
	off_t t;
	union all_data das;
	
	das.sdata.rfd=rfd;
	das.sdata.offset=offset;
	das.sdata.whence=whence;
	
	printf("---> in rpccfop offset %ld\n",offset);

	t=rpcc_fope(LSEEK_REQ, &das);

	return t;
}

int rpccclose(int fd)
{
	int f;
	union all_data das;

	das.cdata.fd=fd;

	f=rpcc_fope(CLOSE_REQ, &das);

	return f;
}

