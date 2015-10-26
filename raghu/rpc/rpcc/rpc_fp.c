#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "rpc_fp.h"
#include "rpc_req.h"
int rpcc_fop(struct rpcc *);
int client_read_req(struct reply_final *srf);
/*open funtion*/
int rpc_open(char *fn, int flag, int mode)
{
	struct rpcc data;
	struct reply_final srf;
	int retval = 0;
	int rretval;
	data.op = 1;
	strcpy(data.u.o.fn, fn);
	data.u.o.flag = flag;
	data.u.o.mode = mode;
	retval = rpcc_fop(&data);
//	printf("rpcc fop retval is : %d\n",retval);
	rretval=client_read_req(&srf);
//	printf("rpcc read retval is : %d\n",rretval);
//	printf("reply fd in rpc : %d\n",srf.urd.ro.fd);	
	return (srf.urd.ro.fd);
}

/*read function*/
int rpc_read(int fd, char *buff, int len)
{
	struct rpcc data;
	struct reply_final srf;
	int retval = 0;
	int rretval;
	data.op= 2;
	data.u.r.fd=fd;
	data.u.r.len=len;
	//strcpy(data.u.r.buff, buff);

	retval = rpcc_fop(&data);
//	printf("read of rpc_fp =%d\n",retval);
	
	//strcpy(buff, data.u.r.buff);
	rretval=client_read_req(&srf);
	strcpy(buff,srf.urd.rr.buff);
	return (srf.urd.rr.fd);
	//return retval;
}

/*write function*/
int rpc_write(int fd, char *buff, int len)
{
	struct rpcc f;
	struct reply_final srf;
	int rretval;
	f.op = 3;
	f.u.w.fd=fd;
	f.u.w.len=len;
	strcpy(f.u.w.buff, buff);
	int retval;
	retval = rpcc_fop(&f);
//	printf("write of rpc_fp =%d\n",retval);
	rretval=client_read_req(&srf);
	return retval;
}

/*close function*/
int rpc_close(int fd)
{
	struct rpcc f;
	struct reply_final srf;
	int rretval;
	int retval;
	f.op = 4;
	f.u.c.fd = fd;
	retval = rpcc_fop(&f);
	rretval=client_read_req(&srf);
//	printf("close of rpc_fp =%d\n",retval);
	return retval;
}
