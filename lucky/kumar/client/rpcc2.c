#include "stdio.h"
#include "fcntl.h"
#include "rpc.h"
#include "rpccfop.h"
#include "rpccfope.h"
#include <string.h>

int rpccopen(char *fname, int mode, int flags)
{
	int fd;
	fop_data_req req;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fname :%s, flags :%d, mode :%d\n", fname, flags, mode);

    req.operation = OPEN_REQUEST;
	strcpy(req.data.odata.filename, fname);  
	req.data.odata.mode = mode;
	req.data.odata.flags = flags;

	fd = rpcc_fope(&req);
	
	printf("-->return fd :%d\n", fd);

	return fd;
}

int rpccread(int rfd,char *buff,int len)
{
	int rd;
	fop_data_req req;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("--> fd :%d, len :%d\n", rfd, len);
	
	printf(" Rbuff value :%s\n",buff);
    
	 req.operation = READ_REQUEST;



//	strcpy(req.data.rdata.buff,buff);
	req.data.rdata.fd=rfd;
	req.data.rdata.len=len;
    //req.fope=2;

	rd=rpcc_fope(&req);
//	strcpy(buff,req.data.odata.buff);

	
//	printf("in rpccfop buff is : %s\n",req.data.odata.rbuff);
	printf ("----r value :%d\n",rd);
	return rd;
}

int rpccwrite(int wfd,char *wbuff,int len)
{
	int w;
	fop_data_req req;
	
//	strcpy(req.data.odata.buff,wbuff);
	req.data.wdata.fd=wfd;
	req.data.wdata.len=len;
    //req.fope=3;

	w=rpcc_fope(&req);

	return w;
}

int rpcclseek(int rfd, int offset, int whence)
{
	int t;
	fop_data_req req;
	
	req.data.sdata.fd=rfd;
	req.data.sdata.offset=offset;
	req.data.sdata.whence=whence;
    //req.fope=4;
	
	printf("---> in rpccfop offset %d\n",offset);

	t=rpcc_fope(&req);

	return t;
}

int rpccclose(int fd)
{
	int f;
	fop_data_req req;

	req.data.cdata.fd=fd;
   // req.fope=5;

	f=rpcc_fope(&req);

	return f;
}

