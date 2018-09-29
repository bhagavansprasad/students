#include "stdio.h"
#include "fcntl.h"
#include <string.h>
//#include "rpccreq.h"
#include "arpc.h"
//#include "rpccfope.h"

fopdata_rep preply;
int rpcc_fope(fopdata_req *req);
int read_from_server(fopdata_rep *preply);
int rpccopen(char *fname, int mode, int flags)
{
	//int fd;
	fopdata_req req;
	
	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fname :%s, flags :%d, mode :%d\n", fname, flags, mode);

	req.fope = OPEN_REQUEST;

	strcpy(req.das.odata.fname, fname);  
	req.das.odata.mode = mode;
	req.das.odata.flags = flags;

	rpcc_fope(&req);
	
	read_from_server(&preply);


	printf("server replay open fd :%d\n",preply.sdas.sodata.fd);
	printf("server replay errno = %d\n",preply.sdas.sodata.erno);

	return 	preply.sdas.sodata.fd;
}
int rpccread(int rfd,char *buff,int len)
{
	//int rd;
	fopdata_req req;

	printf("-->%d. %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("--> fd :%d, len :%d\n", rfd, len);
	
	printf(" Rbuff value :%s\n",buff);

	strcpy(req.das.rdata.rbuff,buff);
	req.das.rdata.rfd = rfd;
	req.das.rdata.len = len;
    req.fope = READ_REQUEST;

	rd = rpcc_fope(&req);
	read_from_server(&preply);
	strcpy(buff,req.das.rdata.rbuff);

	
	printf("in rpccfop buff is : %s\n",req.das.rdata.rbuff);
	printf ("----req value :%d\n",rd);

	return rd;
}

int rpccwrite(int wfd,char *wbuff,int rd)
{
	int w;
	fopdata_req req;

	strcpy(req.das.wdata.wbuff,wbuff);
	req.das.wdata.wfd = wfd;
	req.das.wdata.rd = rd;
    req.fope = WRITE_REQUEST;

	w = rpcc_fope(&req);

	read_from_server(&preply);
	return w;
}

off_t rpcclseek(int rfd, off_t offset, int whence)
{
	off_t t;
	fopdata_req req;

	req.das.sdata.rfd = rfd;
	req.das.sdata.offset = offset;
	req.das.sdata.whence = whence;
    req.fope = LSEEK_REQUEST;
	
	printf("---> in rpccfop offset %ld\n",offset);

 	t = rpcc_fope(&req);

	read_from_server(&preply);
	return t;
}

int rpccclose(int fd)
{
	int f;
	fopdata_req req;

	req.das.cdata.fd = fd;
    req.fope = 5;

	f = rpcc_fope(&req);
	read_from_server(&preply);

	return f;
}
