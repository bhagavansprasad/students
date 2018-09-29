#include "stdio.h"
#include "fcntl.h"
#include "rpcc.h"

int aopen(char *fname,int mode,int flag)
{
	int fd;

	printf("---->%d, %s ,%s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fname:%s, mode:%d, flag:%d\n",fname,mode,flag);

	fd = rpcc_open(fname,mode,flag);
	return fd;
}

int aread(int fd,char *buff,int len)
{
	int r;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);

	r=rpcc_read(fd,buff,len);
	buff[len]='\0';
	printf("--->fd:%d, buff:%s, len:%d\n",fd,buff,len);
	return r;
}

int awrite(int fd,char * buff,int len)
{
	int w;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, buff:%s, len:%d\n",fd,buff,len);

	w=rpcc_write(fd,buff,len);
	return w;
}

int alseek(int fd,off_t k,int whence)
{
	int l;
	printf("--->%d, %s, %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("---->fd:%d, k:%d, whence:%d\n",fd,k,whence);

	l=rpcc_lseek(fd,k,whence);
	return l;
}

int aclose(int fd)
{
	int t;
	t=rpcc_close(fd);
	return t;
}
