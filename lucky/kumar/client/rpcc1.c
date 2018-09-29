#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
#include "rpccfop.h"
int aopen(char *p,int m,int fl)
{
	int fd;
	
	printf("---->%d, %s ,%s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->p:%s, m:%d, fl:%d\n",p,m,fl);

	fd=rpccopen(p,m,fl);
	return fd;
}

int aread(int fd,char *b,int l)
{
	int r;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	
	r=rpccread(fd,b,l);
	b[r]='\0';
	printf("--->fd:%d, b:%s, len:%d\n",fd,b,l);
	return r;
}
int awrite(int fd,char *b,int num)
{
	int w;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, b:%s, len:%d\n",fd,b,num);

	w=rpccwrite(fd,b,num);
	return w;
}
int  alseek(int fd,int p,int q)
{
	int k;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, p:%d, q:%d\n",fd,p,q);

	k=rpcclseek(fd,p,q);
	return k;
}
int aclose(int fd)
{
	int t;
	t=rpccclose(fd);
	return t;
}

