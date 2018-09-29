#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fop.h"
#include "rpc.h"
#include "fop1.h"
#include <string.h>
fop_data_rep sreply;
int rpccopen(char *pathname, int flags, int mode)
{
	fop_data_req req;
	req.operation=OPEN_REQUEST;
	strcpy(req.data.odata.filename,pathname);
	req.data.odata.flags=flags;
	req.data.odata.mode=mode;
	rpcc_fop(&req);
	read_from_server(&sreply);
	printf("server open replay fd = %d\n",sreply.sudata.sodata.fd);
	printf("server open replay errno = %d\n",sreply.sudata.sodata.error);
	return sreply.sudata.sodata.fd;
}
int rpccread(int fd, char *buff, int len)
{
	fop_data_req req;
	req.operation=READ_REQUEST;
	req.data.rdata.fd=fd;
	req.data.rdata.len=len;
	rpcc_fop(&req);
	read_from_server(&sreply);
	printf("server read replay retval = %d\n",sreply.sudata.srdata.retval);
	printf("server read replay buffer = %s\n",sreply.sudata.srdata.buff);
	printf("server read replay errno = %d\n",sreply.sudata.srdata.error);
	return sreply.sudata.srdata.retval;

}
int rpccwrite(int fd, char *buff, int len)
{
	fop_data_req req;
	req.operation=WRITE_REQUEST;
	req.data.wdata.fd=fd;
	strcpy(req.data.wdata.buff,buff);
	req.data.wdata.len=len;
	rpcc_fop(&req);
	read_from_server(&sreply);
	printf("server write replay retval = %d\n",sreply.sudata.swdata.retval);
	printf("server write replay errno = %d\n",sreply.sudata.swdata.error);
	return sreply.sudata.swdata.retval;
}
int rpcclseek(int fd, int offset, int whence)
{
	fop_data_req req;
	req.operation=LSEEK_REQUEST;
	req.data.seekdata.fd=fd;
	req.data.seekdata.offset=offset;
	req.data.seekdata.whence=whence;
	rpcc_fop(&req);
	read_from_server(&sreply);
	printf("server lseek replay newoffset = %d\n",sreply.sudata.sseekdata.newoffset);
	printf("server lseek replay errno = %d\n",sreply.sudata.sseekdata.error);
return sreply.sudata.sseekdata.newoffset;
}
int rpccclose(int fd)
{
	fop_data_req req;
	req.operation=CLOSE_REQUEST;
	req.data.cdata.fd=fd;
	rpcc_fop(&req);
	read_from_server(&sreply);
	printf("server close replay fd = %d\n",sreply.sudata.scdata.fd);
	printf("server close replay errno = %d\n",sreply.sudata.scdata.error);
	return sreply.sudata.scdata.fd;
}
