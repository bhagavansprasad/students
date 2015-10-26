#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include <string.h>
#include "rpcc.h"
#include "rpcc_fop.h"
/*#define OPEN 1
#define READ 2
#define WRITE 3
#define LSEEK 4
#define CLOSE 5*/
struct ch q;
int op,r,w,ls,cl;

int rpcc_open(char *fd, int mode,int flag)
{
	strcpy(q.t.ope.p,fd);
	q.t.ope.m=mode;
	q.t.ope.f=flag;
	q.i=1;
	op=rpcc_fop(&q);
	return op;
}

int rpcc_read(int fd, char *b,int len)
{
	q.t.rd.m=fd;
	strcpy(q.t.rd.b,b);
	q.t.rd.f=len;
	q.i=2;
	r=rpcc_fop(&q);
	strcpy(b,q.t.rd.b);
	return r;
}

int rpcc_write(int fd, char *b, int len)
{
	q.t.wtr.m=fd;
	strcpy(b,q.t.wtr.b);
	q.t.wtr.f=len;
	q.i=3;
	w=rpcc_fop(&q);
	return w;
}

off_t rpcc_lseek(int fd,off_t p,int qr)
{
	q.t.lsk.m=fd;
	q.t.lsk.p=p;
	q.t.lsk.qr=qr;
	q.i=4;
	ls=rpcc_fop(&q);
	return ls;
}

int rpcc_close(int fd)
{
	q.t.cls.m=fd;
	q.i=5;
	cl=rpcc_fop(&q);
	return cl;
}
//rpcc_send_data(&q);
