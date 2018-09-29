#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
#include "rpcc.h"
#include "arpc.h"
int aopen(char *fname,int mode,int flags)
{
	int fd = -1;
	
	printf("---->%d, %s ,%s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fn:%s, m:%d, fl:%d\n",fname,mode,flags);

	fd=rpccopen(fname,mode,flags);
	return fd;
}
int aread(int fd,char *b,int l)
{
	int rd;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	
	rd = rpccread(fd,b,l);
	b[rd]='\0';
	printf("--->fd:%d, b:%s, len:%d\n",fd,b,l);
	return rd;
}
int awrite(int fd,char *b,int rd)
{
	int w;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, b:%s, rd:%d\n",fd,b,rd);

	w=rpccwrite(fd,b,rd);
	return w;
}
off_t alseek(int fd,off_t p,int q)
{
	int k;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, p:%ld, q:%d\n",fd,p,q);

	k=rpcclseek(fd,p,q);
	return k;
}
int aclose(int fd)
{
	int t;
	t=rpccclose(fd);
	return t;
}
