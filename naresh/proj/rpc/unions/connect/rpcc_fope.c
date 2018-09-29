#include "fcntl.h"
#include "rpcc_fope.h"
#include "string.h"
int rpcc_fope(fopdata *n)
{
	switch(n->fope)
	{
	int fd,r,w,l,t;
	case 1:
		int fd;
		fd = open(n->das.odata.fname, r->das.odata.mode, r->das.odata.flag);
		return fd;
	case 2:
		int r;
		r = read(n->das.rdata.fd, r->das.rdata.buff, r->das.rdata.len);
		return r;
	case 3:
		int w;
		w = write(n->das.wdata.fd, r->das.wdata.buff, r->das.wdata.len);

		return w;
	case 4:	
		off_t l;
		l = lseek(n->das.ldata.fd, r->das.ldata.t, r->das.odata.num);

		return l;
	case 5:
		int t;
		t = close(n->das.cdata.fd);
		return t;
	default:
		printf("no valid file\n");
		break;
}
