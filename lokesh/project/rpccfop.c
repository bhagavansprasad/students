#include "stdio.h"
#include "fcntl.h"
#include "rpccfop.h"
#include "rpccfope.h"
#include "string.h"
#define OPEN_REQ 1
#define READ_REQ 2
#define WRITE_REQ 3
#define LSEEK_REQ 4
#define CLOSE_REQ 5
struct loke n;
int rpccopen(char*fname,int mode,int flags)
{
int fd;

strcpy(odata.fname,fname);
n.uni.odata.mode=mode;
n.uni.odata.flags=flags;
n.fope=1;
fd=rpcc_fope(&n);

return fd;
}

int rpccread(int rfd,char *rbuff,int len)
{
int r;

strcpy(rdata.rbuff,rbuff);
n.uni.rdata.rfd=rfd;
n.uni.rdata.len=len;
n.fope=2;
r=rpcc_fope(&n);
strcpy(rbuff,n.rdata.rbuff);
 return r;
 }
 int rpccwrite(int wfd, char *wbuff,int len)
 {
 int w;
 n.uni.wdata.wfd=wfd;
strcpy(n.wdata.wbuff,wbuff);
n.uni.wdata.len=len;
n.fope=3;
w=rpcc_fope(&n);
 return w;
 }

 off_t rpcclseek(int rfd,off_t offset,int whence)
 {
 off_t t;
 

 n.uni.sdata.rfd=rfd;
 n.uni.sdata.offset=offset;
 n.uni.sdata.whence=whence;
 n.fope=4;
t=rpcc_fope(&n);

return t;

}
int rpccclose(int fd)
{
int f;


n.uni.cdata.fd=fd;
n.fope=5;
f=rpcc_fope(&n);
return f;
}


