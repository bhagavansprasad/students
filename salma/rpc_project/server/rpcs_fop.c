#include<stdio.h>
#include"struct.h"
#include"strc.h"
#include"enum.h"
int rpcs_fop(struct ch *q,struct server *y)
{
	printf("final operation :%d\n",q->flag);
	switch(q->flag)
	{
		case open_req:
			y->ts.o.fd=open(q->t.o.p,q->t.o.m,q->t.o.f);
			if(y->ts.o.fd==-1)
				printf("--->file is not open\n");
			printf("--->final path name is :%s\n",q->t.o.p);
			printf("--->file open is :%d\n",y->ts.o.fd);
			return(y->ts.o.fd);
		case read_req:
			y->ts.r.retval=read(q->t.r.m,q->t.r.b,q->t.r.f);
			q->t.r.b[y->ts.r.retval]='\0';
			printf("buff is --->%s\n",q->t.r.b);
			if(y->ts.r.retval==-1)
			{
				printf("---->file reading is failed\n");
			}
			strcpy(y->ts.r.buf,q->t.r.b);
				return(y->ts.r.retval);
		case write_req:
			y->ts.w.retval=write(q->t.w.m,q->t.w.b,q->t.w.f);
			if(y->ts.w.retval==-1)
			{
				printf("---> file writing is failed\n");
			}
			return y->ts.w.retval;
		case close_req:
			return(close(q->t.c.m));
		default:
			printf("wrong value \n");
	}

}

