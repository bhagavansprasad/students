#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include "unistd.h"
#include"rpc1.h"
#include "rpcc_fop.h"

int rpc_open(char * s,int flags,int mode)
{
	struct rpcc a;
	strcpy(a.u.o.s,s),a.u.o.flags=flags,a.u.o.mode=mode,a.op=1;
	int retval=rpcc_send_req (&a);
	return retval;
}

int rpc_read(int t,char *buff,int l)
{
	struct rpcc a;
	a.u. r.t=t,strcpy(a.u.r.buff,buff),a.u.r.l=l,a.op=2;
	int retval= rpcc_send_req (&a);
	strcpy(buff,a.u.r.buff);
//	printf("rpc1:%s\n",buff);
	return retval;
}

int rpc_write(int t1,char  *buff,int rval)
{
	struct rpcc a;  
	a.u. w.t1=t1,strcpy(a.u.w.buff,buff),a.u.w.rval=rval,a.op=3;  
	int retval=rpcc_send_req(&a);
	return retval;
}

int rpc_close(int t1)
{  
	struct rpcc a;
	a.u.c.t1=t1,a.op=4;
	int retval=rpcc_send_req (&a);
	return retval;
}
