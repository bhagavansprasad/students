#include "stdio.h"
#include "fcntl.h"
#include "struct.h"
#include "rpcc.h"
int rpcc_fop(struct ch *q)
{
int fd,r,w,ls,t;
	switch (q->i)
	{	
		case 1:
				fd=open(q->t.ope.p,q->t.ope.m,q->t.ope.f);
				return fd;
				break;
		
		default:
				printf("there are no elements:");
				break;
		
		
		case 2:
		   		r=read(q->t.rd.m,q->t.rd.b,q->t.rd.f);
				return r;
				break;
		case 3:
				w=write(q->t.wtr.m,q->t.wtr.b,q->t.wtr.f);
				return w;
				break;
		case 4:
				ls=lseek(q->t.lsk.m,q->t.lsk.p,q->t.lsk.qr);
			//	printf("-->length :%d\n",p);
			//	printf("-->y :%d\n",qr);
				return ls;
				break;
		case 5:
				t=close(q->t.cls.m);
				return t;
				break;
	
	}
}
