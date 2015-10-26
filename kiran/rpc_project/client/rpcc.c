#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "string.h"
#include "structure.h"
#include "rpcc_fop.h"
int client_read_from_server(fop_data_rep *sreplay);

fop_data_req creq;
fop_data_rep sreplay;

int rpcc_open(char *pathname, int mode, int flags)
{
	creq.ope = OPEN_REQUEST;
	strcpy(creq.t.op.pathname,pathname);
	creq.t.op.flags = flags;
	creq.t.op.mode = mode;
	rpcc_fop(&creq);
	client_read_from_server(&sreplay);
	printf("/* CLIENT : SERVER OPEN REPLAY */\n");
	printf("server open replay fd          =  %d\n",sreplay.u.open.fd);
	if(sreplay.u.open.fd < 0)
	{
		printf("server open replay errno       =  %d\n",sreplay.u.open.error);
	}

	return (sreplay.u.open.fd);
}    

int rpcc_read(int fd, char *buf, int count)
{
	creq.ope = READ_REQUEST;
	creq.t.rd.fd = fd;
	creq.t.rd.count = count;
	rpcc_fop(&creq);
	client_read_from_server(&sreplay);
	strcpy(buf, sreplay.u.read.buf);
	buf[sreplay.u.read.rretval] = '\0';
	printf("/* CLIENT : SERVER READ REPLAY */\n");
	printf("server read replay rretval     =  %d\n",sreplay.u.read.rretval);
	printf("server read replay buff        =  %s\n",sreplay.u.read.buf);
	if(sreplay.u.read.rretval < 0)
	{
		printf("server read replay errno       =  %d\n",sreplay.u.read.error);
	}

	return sreplay.u.read.rretval;
}

int rpcc_write(int fd, char *buf, int count)
{
	creq.ope = WRITE_REQUEST;
	creq.t.wr.fd = fd;
	strcpy(creq.t.wr.buf,buf);
	creq.t.wr.count = count;
	rpcc_fop(&creq);
	client_read_from_server(&sreplay);
	printf("/* CLIENT : SERVER WRITE REPLAY */\n");
	printf("server write replay retval     =  %d\n",sreplay.u.write.wretval);
	if(sreplay.u.write.wretval < 0)
	{
		printf("server write replay errno  =  %d\n",sreplay.u.write.error);
	}

	return sreplay.u.write.wretval;
}

int rpcc_lseek(int fd, off_t offset, int whence)
{
	creq.ope = LSEEK_REQUEST;
	creq.t.sk.fd = fd;
	creq.t.sk.offset = offset;
	creq.t.sk.whence = whence;
	rpcc_fop(&creq);
	client_read_from_server(&sreplay);
	printf("/* CLIENT : SERVER LSEEK REPLAY */\n");
	printf("server lseek replay retval     =  %d\n",sreplay.u.lseek.offset);
	if(sreplay.u.lseek.offset < 0)
	{
		printf("server write replay errno  =  %d\n",sreplay.u.lseek.error);
	}
	return sreplay.u.lseek.offset;
}

int rpcc_close(int fd)
{
	creq.ope = CLOSE_REQUEST;
	creq.t.cls.fd = fd;
	rpcc_fop(&creq);
	client_read_from_server(&sreplay);
	printf("/* CLIENT : SERVER CLOSE REPLAY */\n");
	printf("server close replay retval 	   =  %d\n",sreplay.u.close.fd);
	if(sreplay.u.close.fd < 0)
	{
		printf("server write replay errno      =  %d\n",sreplay.u.close.error);
	}
	return sreplay.u.close.fd;
}
