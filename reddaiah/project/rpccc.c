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

