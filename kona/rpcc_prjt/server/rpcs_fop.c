#include <stdio.h>
#include <string.h>
#include "struct_client.h"
#include "struct_server.h"
#include "enume.h"
enum a;
int fact(int num);
int rpcs_fop(struct ch *q,struct server *y)
{
	printf("final operation: %d\n",q->flag);
	switch(q->flag)
	{
		case open_req:
			y->ts.o.fd = open(q->t.o.p ,q->t.o.m,q->t.o.f);
			if(y->ts.o.fd==-1)
			{
				printf("------>file is not open");
			}
			printf("----->final path name is : %s\n",q->t.o.p);
			printf("----->file open is:%d\n",y->ts.o.fd);
			return 	y->ts.o.fd ;
		case read_req:
			y->ts.r.retval=read(q->t.r.m ,q->t.r.b,q->t.r.f);
			q->t.r.b[y->ts.r.retval]='\0';
			printf("buff is---->%s\n",q->t.r.b);
			if(y->ts.r.retval==-1)
			{
				printf("------>file reading is filed");
			}
			strcpy(y->ts.r.buf,q->t.r.b);
			return 	y->ts.r.retval;


		case write_req:
			y->ts.w.retval= write(q->t.w.m ,q->t.w.b,q->t.w.f);
			if(y->ts.w.retval==-1)
			{
				printf("------>file writing is filed");
			}
			return y->ts.w.retval;

		case add_req:
			y->ts.sa.rval=(q->t.a.val1)+(q->t.a.val2);
			return y->ts.sa.rval;

		case fact_req:
			y->ts.sf.fval=fact(q->t.f.val4);
			return y->ts.sf.fval;

		case addafter_req:
		y->ts.saddval.addval=addafter(q->t.ad.val5);
			return y->ts.saddval.addval;

		case close_req:
			return (close(q->t.c.m ));
		default:
			printf("wrong value\n");
	}
}
