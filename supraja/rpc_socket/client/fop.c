#include <sys/types.h>
#include <unistd.h>
#include "rpcc.h"
#include <stdio.h>
int aopen(char *fn,int flags,int mode)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	return(rpcc_open(fn,flags,mode));
}
int aread(int fd,char* buff,int len)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	return(rpcc_read(fd,buff,len));
}
int awrite(int fd,char * buff,int rval)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	return(rpcc_write(fd,buff,rval));
}
int alseek(int fd,off_t l,int pos)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	return(rpcc_lseek(fd,l,pos));
}
int aclose(int fd)
{
	printf("%d %s \n ",__LINE__,__FILE__);
	return(rpcc_close(fd));
}
