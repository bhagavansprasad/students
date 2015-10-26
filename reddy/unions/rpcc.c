#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include <string.h>
#include "rpcc.h"
#include "rpcc_fop.h"
#define OPEN 1
#define READ 2
#define WRITE 3
#define LSEEK 4
#define CLOSE 5
struct ch q;
int op,r,w,ls,cl;

int rpcc_open(char *fd, int mode,int flag)
{
	strcpy(q.t.ope.p,fd);
	q.t.ope.m=mode;
	q.t.ope.f=flag;
	op=rpcc_fop(&q);
}

int rpcc_read(int fd, char *b,int len)
{
	q.t.rd.m=fd;
	strcpy(q.t.rd.b,b);
	q.t.rd.f=len;
	r=rpcc_fop(&q);
}

int rpcc_write(int fd, char *b, int len)
{
	q.t.wtr.m=fd;
	strcpy(q.t.wtr.b,b);
	q.t.wtr.f=len;
	w=rpcc_fop(&q);
}

off_t rpcc_lseek(int fd,off_t p,int qr)
{
	q.t.lsk.m=fd;
	q.t.lsk.p=p;
	q.t.lsk.qr=qr;
	ls=rpcc_fop(&q);
}

int rpcc_close(int fd)
{
	q.t.cls.m=fd;
	cl=rpcc_fop(&q);
}
