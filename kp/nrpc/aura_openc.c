#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#include "define.h"
#include "comm_oper.h"

int aura_openc(char *fname, int flags)
{
	fop_data datac;

	fop_data reply;
	datac.cmd = FILE_OPEN;
	strcpy(datac.udata.opn.fname, fname);
	datac.udata.opn.mode = flags;


	rpc_send_request(&datac);
	rpc_recv_reply(&reply);
	return reply.udata.opn.fd;
}
/* 
 
int aura_readc(int fd, char *buf, int count)
{
	fop_data datac;
	fop_data reply;

	datac.cmd = FILE_READ;
	datac.udata.rdwt.fd = fd;
	datac.udata.rdwt.count = count;
	strncpy(buf, datac.udata.rdwt.buffer, datac.udata.rdwt.count);
	rpc_send_request(&datac);
	rpc_recv_reply(&reply);
	return reply.udata.rdwt.count;

}

int aura_writec(int fd, char *buf, int count)
{
	fop_data datac;
	fop_data reply;

	datac.cmd = FILE_WRITE;
	datac.udata.rdwt.fd=fd;
	strncpy(buf,datac.udata.rdwt.buffer, datac.udata.rdwt.count);
	datac.udata.rdwt.count=count;
	rpc_send_request(&datac);
	rpc_recv_reply(&reply);
	return datac.udata.rdwt.count;
}

int aura_lseekc(int fd, off_t offset, int whence)
{
	fop_data datac;
	fop_data reply;

	datac.cmd = FILE_SEEK;
	datac.udata.seek.fd=fd;
	datac.udata.seek.offset=offset;
	datac.udata.seek.whence=whence;
	rpc_send_request(&datac);
	rpc_recv_reply(&reply);
	return datac.udata.seek.offset;
}

int aura_closec(int fd)
{
	fop_data datac;
	//fop_data reply;

	datac.cmd=FILE_CLOSE;
	datac.udata.cls.fd=fd;
	rpc_send_request(&datac);
//	rpc_recv_reply(&reply);

	return 0;
} 
*/
