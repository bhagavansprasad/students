#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"
#include "rpccfope.h"
#include <string.h>
#include "arpc.h"
#define OPEN_REQ 1
#define READ_REQ 2
#define WRITE_REQ 3
#define CLOSE_REQ 5
#define LSEEK_REQ 4

fopdata_req req;

int rpccopen(char *fname, int mode, int flags)
{
	int fd;
	fopdata client_data;
	int retval = 0;
	
	client_data.fope = OPEN_REQ;
	strcpy(r.das.odata.fname, fname);  
	r.das.odata.mode = mode;
	r.das.odata.flags = flags;
    r.fope = 1;
	fd=rpcc_fope(&r);
	
	printf("-->return fd :%d\n", fd);

	return fd;
}

int rpccread(int rfd,char *buff,int len)
{
	int rd;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("--> fd :%d, len :%d\n", rfd, len);
	
	printf(" Rbuff value :%s\n",buff);

	strcpy(r.das.rdata.rbuff,buff);
	r.das.rdata.rfd=rfd;
	r.das.rdata.len=len;
    r.fope=2;

	rd=rpcc_fope(&r);
	strcpy(buff,r.das.rdata.rbuff);

	
	printf("in rpccfop buff is : %s\n",r.das.rdata.rbuff);
	printf ("----r value :%d\n",rd);
	return rd;
}

int rpccwrite(int wfd,char *wbuff,int rd)
{
	int w;
	
	strcpy(r.das.wdata.wbuff,wbuff);
	r.das.wdata.wfd=wfd;
	r.das.wdata.rd=rd;
    r.fope=3;

	w=rpcc_fope(&r);

	return w;
}

off_t rpcclseek(int rfd, off_t offset, int whence)
{
	off_t t;
	
	r.das.sdata.rfd=rfd;
	r.das.sdata.offset=offset;
	r.das.sdata.whence=whence;
    r.fope=4;
	
	printf("---> in rpccfop offset %ld\n",offset);

	t=rpcc_fope(&r);

	return t;
}

int rpccclose(int fd)
{
	int f;

	r.das.cdata.fd=fd;
    r.fope=5;

	f=rpcc_fope(&r);

	return f;
}

