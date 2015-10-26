#include <sys/types.h>
#include <unistd.h>
#include "rpc1.h"
int aopen(char *fn,int flags,int mode)
{
	return(rpcc_open(fn,flags,mode));
}
int aread(int fd,char* buff,int len)
{
	return(rpcc_read(fd,buff,len));
}
int awrite(int fd,char * buff,int rval)
{
	return(rpcc_write(fd,buff,rval));
}
int alseek(int fd,off_t l,int pos)
{
	return(rpcc_lseek(fd,l,pos));
}
int aclose(int fd)
{
	return(rpcc_close(fd));
}
