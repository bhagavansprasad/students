#include <stdio.h>
#include <fcntl.h>
#include "rpcc.h"
int aopen(char *p, int mode, int flag)
{
	int fd,len;

	printf("---->%d, %s ,%s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->path:%s, mode:%d, flag:%d\n",p,mode,flag);

	fd=rpcc_open(p,mode,flag);
	return fd;
}

int aread(int fd, char *buff, int len)
{
	int r;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);

	r=rpcc_read(fd,buff,len);
	buff[r]='\0';
	printf("in fop buff is:%s\n",buff);
	return r;
}

int awrite(int fd, char *buff, int len)
{
	int w;
	printf("----->%d,%s,%s\n",__LINE__,__FUNCTION__,__FILE__);

	w=rpcc_write(fd,buff,len);
	return w;
}

off_t alseek(int fd, off_t p,int qr)
{
	int ls;
	printf("----->%d,%s,%s\n",__LINE__,__FUNCTION__,__FILE__);
//	printf("------>fd:%d\n,function: %s\n, file:%s\n",fd,p,qr);

	ls=rpcc_lseek(fd,p,qr);
	return ls;
}

int aclose(int fd)
{
	int cl;
	cl=rpcc_close(fd);
	return cl;
}
