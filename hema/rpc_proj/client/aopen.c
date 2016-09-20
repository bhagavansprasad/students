#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int aopen(char *filename,int mode,int flags)
{
	int fd=rpc_open(filename,mode,flags);

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	return fd;
}

int aread(int fd,char *buff,int len)
{
	int rval=rpc_read(fd,buff,len);

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	return rval;
}

int awrite(int fd,char *buff,int rval)
{
	int wval=rpc_write(fd,buff,rval);

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	return wval;
}

off_t alseek(int fd,off_t s,int whence)
{
	int lval= rpc_lseek(fd,s,whence);

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	return lval;
	
}

int aclose(int fd)
{
	int t=rpc_close(fd);

	printf("-->C,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	return t;
}


