#include <sys/stat.h>
#include <unistd.h>
#include "string.h"
#include "structure.h"
#include "rpcc_fop.h"
#include "comm_defs.h"

struct fopdata d;
int rpcc_open(char *pathname, int mode, int flags)
{
	int fd;
	d.operation = FOP_OPEN_REQ; 
	strcpy(d.t.op.pathname,pathname);
	d.t.op.flags = flags;
	d.t.op.mode = mode;
	fd=rpcc_fop(&d);	
	return fd;
}   

int rpcc_read(int fd, char *buf, int count)
{
	int r;
	d.operation = FOP_READ_REQ; 
	d.t.rd.fd = fd;
	d.t.rd.count = count;
	r = rpcc_fop(&d);
	strcpy(buf, d.t.rd.buf); 

	return r;
}

int rpcc_write(int fd, char *buf, int count)
{
	int w;
	d.operation = FOP_WRITE_REQ;
	d.t.wr.fd = fd;
	strcpy(d.t.wr.buf,buf);
	d.t.wr.count = count;
	w=rpcc_fop(&d);
	return w;
}

int rpcc_lseek(int fd, off_t offset, int whence)
{
	int q;
	d.operation = FOP_LSEEK_REQ;
	d.t.sk.fd = fd;
	d.t.sk.offset = offset;
	d.t.sk.whence = whence;
	q=rpcc_fop(&d);
	return q;
}

int rpcc_close(int fd)
{
	int c;
	d.operation = FOP_CLOSE_REQ; 
	d.t.cls.fd = fd;
	c=rpcc_fop(&d);
	return c;
}
