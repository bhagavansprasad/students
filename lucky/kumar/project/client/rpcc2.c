#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fop.h"
#include "rpc.h"
#include "fop1.h"
#include <string.h>
int read_from_server(fop_data_rep *preply);

fop_data_rep preply;
int rpccopen(const char *pathname, int flags, mode_t mode)
{
	
	fop_data_req req;
	req.operation=OPEN_REQUEST;
	strcpy(req.data.odata.filename,pathname);
	req.data.odata.flags=flags;
	req.data.odata.mode=mode;
	rpcc_fop(&req);
	read_from_server(&preply);
	printf("server reply open fd value = %d\n",preply.sudata.sodata.fd);
	return preply.sudata.sodata.fd;
}
ssize_t rpccread(int fd, void *buf, size_t count)
{
	
	fop_data_req req;
    req.operation=READ_REQUEST;
	req.data.rdata.fd=fd;
	req.data.rdata.len = count;
	rpcc_fop(&req);
	read_from_server(&preply);
	printf("server reply read retval value = %d\n",preply.sudata.srdata.retval);
	printf("server reply read buff value = %s\n",preply.sudata.srdata.buff);
	return preply.sudata.srdata.retval;
}
ssize_t rpccwrite(int fd, void *buf, size_t count)
{
	
	fop_data_req req;
	req.operation=WRITE_REQUEST;
	req.data.wdata.fd=fd;
	strcpy(buf,	req.data.wdata.buff);
	req.data.wdata.len=count;
	rpcc_fop(&req);
	read_from_server(&preply);
	printf("server reply write retval value = %d\n",preply.sudata.swdata.retval);
	return preply.sudata.swdata.retval;
}
off_t rpcclseek(int fd, off_t offset, int whence)
{
	
	fop_data_req req;
	req.operation=LSEEK_REQUEST;
	req.data.seekdata.fd=fd;
	req.data.seekdata.offset=offset;
	req.data.seekdata.whence=whence;
	rpcc_fop(&req);
	read_from_server(&preply);
	printf("server reply lseek newoffset value = %d\n",preply.sudata.sseekdata.newoffset);
	return preply.sudata.sseekdata.newoffset;
}
int rpccclose(int fd)
{

    fop_data_req req;
	req.operation=CLOSE_REQUEST;
	req.data.cdata.fd=fd;
	rpcc_fop(&req);
	read_from_server(&preply);
	printf("server reply close fd value = %d\n",preply.sudata.scdata.fd);
    return preply.sudata.scdata.fd;
}
