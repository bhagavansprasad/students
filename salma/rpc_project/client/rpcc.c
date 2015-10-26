#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include"strc.h"
#include"struct.h"
#include"enum.h"
struct ch q;
struct server y;
int rpcc_fop(struct ch *);
int client_read(struct server *);
int rpc_open(char *p,int mode,int flag)
{
int rrval=-1;
q.flag=open_req;
strcpy(q.t.o.p,p);
q.t.o.m=mode;
q.t.o.f=flag;
int rval=rpcc_fop(&q);
rrval=client_read(&y);
printf("in rpcc_client rrval is %d\n",rrval);
printf("in rpcc_fd is %d\n",y.ts.o.fd);
return(y.ts.o.fd);
}
int rpc_read(int fd,char *b,int len)
{
q.flag=read_req;
q.t.r.m=fd;
strcpy(q.t.r.b,b);
q.t.r.f=len;
int w=rpcc_fop(&q);
client_read(&y);
strcpy(b,y.ts.r.buf);
b[y.ts.r.retval]='\0';
printf(" rpcc_buf is %s\n",b);
return(y.ts.r.retval);
}
int rpc_write(int r,char *b,int len)
{
q.flag=write_req;
q.t.w.m=r;
strcpy(q.t.w.b,b);
q.t.w.f=len;
rpcc_fop(&q);
client_read(&y);
return(y.ts.w.retval);
}
int rpc_close(int fd)
{
q.flag=close_req;
q.t.c.m=fd;
rpcc_fop(&q);
client_read(&y);
return(y.ts.c.retval);
}

