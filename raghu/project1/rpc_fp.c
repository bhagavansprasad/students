#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "rpcc_fp.h"
#include "struct.h"
/*struct open
{
	char fn[100];
	int flag;
	int mode;
};
struct read
{
	int fp;
	char buff[100];
	int len;
};
struct write
{
	int fp;
	char buff[100];
	int len;
};
struct close
{
	int fn;
};
union rpc
{
	struct open o;
	struct read r;
	struct write w;
	struct close c;
};
struct rpcc
{
	int op;
	union rpc u;
};*/
struct rpcc f;
//struct rpcc *f;

/*open funtion*/
int rpc_open(char *fn,int flag, int mode)
{
	f.op=1;
	f.u.o.flag=flag;
	f.u.o.mode=mode;
	strcpy(f.u.o.fn,fn);
	return(rpcc_fop(f));
}

/*read function*/
int rpc_read(int fp,char *buff,int len)
{
	f.op=2;
	f.u.r.fp=fp;
	f.u.r.len=len;
	strcpy(f.u.r.buff,buff);
	return(rpcc_fop(f));
}

/*write function*/
int rpc_write(int fp,char *buff,int len)
{
	f.op=3;
	f.u.w.fp=fp;
	f.u.w.len=len;
	strcpy(f.u.w.buff,buff);
	return(rpcc_fop(f));
}

/*close function*/
int rpc_close(int fn)
{
	f.u.c.fn=fn;
	return(rpcc_fop(f));
	
}
