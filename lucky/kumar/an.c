#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"structdefs.h"
#include"union.h"
#include "op.h"
int rpcc_fop(int i,union rpc *u1)
{
	if(i==1)
	{
		int fd;
		fd=open(u1->o1.pathname,u1->o1.flags,u1->o1.mode);
		return fd;
	}
	else if(i==2)
	{
		int r;
		r=read(u1->r1.fd,u1->r1.buf,u1->r1.count);
		return r;
	}
	else if(i==3)
	{
		int w;
		w=write(u1->w1.fd,u1->w1.buf,u1->w1.count);
		return w;

	}
	else if(i==4)
	{
		int l;
		l=lseek(u1->l1.fd,u1->l1.offset,u1->l1.whence);
		return l;
	}
	else if(i==5)
	{
		int c;
		c=close(u1->c1.fd);
		return c;
	}
	return 0;
}
