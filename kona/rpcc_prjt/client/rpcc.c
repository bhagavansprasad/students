#include<fcntl.h> 
#include<string.h> 
#include<stdio.h> 
//#include "rpcc.h"
#include "struct_client.h"
#include "struct_server.h"
#include "enume.h"
struct ch q;
struct server y;
enum a;
int rpcc_fop(struct ch *);
int client_read(struct server *);
int rpc_open(char *p, int mode, int flag)
{
	int rrval=-1;
	q.flag=open_req;
	strcpy(q.t.o.p,p);
	q.t.o.m=mode;
	q.t.o.f=flag;
	int rval = rpcc_fop(&q);
	rrval = client_read(&y);
	printf("---> in rpcc client rrval is : %d\n",rrval);
	printf("--> in rpcc fd is : %d\n",y.ts.o.fd);
	return (y.ts.o.fd);

}
int rpc_read(int fd, char *b, int len)
{
	q.flag = read_req;
	q.t.r.m = fd;
	strcpy(q.t.r.b, b);
	q.t.r.f = len;
	int	w = rpcc_fop(&q);
	//strcpy(b , q.t.r.b);
	//return w;
	client_read(&y);
	strcpy(b,y.ts.r.buf);
	b[y.ts.r.retval]='\0';
	printf("--> in rpcc buff is : %s\n",b);
	return (y.ts.r.retval);
}
int rpc_write(int r,char *b,int len )
{
	q.flag=write_req;
	q.t.w.m=r;
	strcpy(q.t.w.b , b);
	q.t.w.f=len;
	rpcc_fop(&q);
	client_read(&y);
	return (y.ts.w.retval);

}
int rpc_add(int a,int b)
{
	q.flag=add_req;
	q.t.a.val1=a;
	q.t.a.val2=b;
	rpcc_fop(&q);
	client_read(&y);
	return (y.ts.sa.rval);

}

int rpc_fact(int n)
{
	q.flag=fact_req;
	q.t.f.val4=n;
	rpcc_fop(&q);
	client_read(&y);
	return (y.ts.sf.fval);
}

int rpc_addafter(int no)
{
	q.flag=addafter_req;
	q.t.ad.val5=no;
	rpcc_fop(&q);
	client_read(&y);
	return (y.ts.saddval.addval);
}
int rpc_close(int fd)
{
	q.flag=close_req;
	q.t.c.m=fd;
	rpcc_fop(&q);
	client_read(&y);
	return (y.ts.c.retval);
}
