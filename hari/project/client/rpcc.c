#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include "structc.h"
#include "structs.h"
#include "enum.h"
struct ch q;
struct server y;
enum a;
int rpcc_fop(struct ch *);
int client_read(struct server *);
int rpc_open(char*p,int mode,int flag)
{
 int rrval=-1;
 q.flag=open;
 strcpy(q.t.o.p,p);
 q.t.o.m=mode;
 q.t.o.f=flag;
 int rval=rpcc_fop(&q);
 rrval=client_read(&y);
 printf("----->in rpcc client rrval is:%d\n",rrval);
 printf("-->in rpcc fd is:%d\n",y.ts.o.fd);
 return(y.ts.o.fd);
 }
 int rpc_read(int fd, char*b,int len)
 {
  q.flag=read;
  q.t.r.m=fd;
  strcpy(q.t.r.t.b,b);
  q.t.r.f=len;
  int w=rpcc_fop(&q);
  client_read(&y);
  strcpy(b.y.ts.r.buf);
  b[y.ts.r.r.retval]='\0';
  printf("--->in rpcc buff is :%s\n",b);
  return(y.ts.r.retval);
  }
  int rpc_write(int r, char*b,int len)
  {
   q.flag=write;
   q.t.w.m=r;
   strcpy(q.t.w.b,b);
   q.t.w.f=len;
   rpcc_fop(&q);
   client_read(&y);
   return(y.ts.w.retval);
   }
   int rpc_close(int fd)
   {
   q.flag=close;
   q.t.c.m=fd;
   rpcc_fop(&q);
   client_read(&y);
   return(y.ts.c.retval);
   }

