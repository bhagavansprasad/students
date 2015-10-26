#include <unistd.h>
#include <fcntl.h>
#include "comm_defs.h"
#include "structure.h"

int rpcc_fop(struct fopdata *d)
{
	if(d->operation == FOP_OPEN_REQ)
	{
		int fd = 0;

		fd = open(d->t.op.pathname, d->t.op.mode, d->t.op.flags);

		return fd;
	}    
	else if(d->operation == FOP_READ_REQ)
	{
		int r = 0;  

		r = read(d->t.rd.fd, d->t.rd.buf, d->t.rd.count);

		return r;
	}
	else if(d->operation==FOP_WRITE_REQ)
	{
		int w = 0;
		w=write(d->t.wr.fd,d->t.wr.buf,d->t.wr.count);

		return w;
	}
	else if(d->operation==FOP_LSEEK_REQ)
	{
		int q = 0;
		q=lseek(d->t.sk.fd,d->t.sk.offset,d->t.sk.whence);

		return q;
	}
	else if(d->operation==FOP_CLOSE_REQ)
	{
		int c = 0;
		c=close(d->t.cls.fd);

		return c;
	}
	return 0;
}
