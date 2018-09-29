#include <sys/types.h>
#include <unistd.h>
#include "rpcc.h"
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
int aget_first()
{
	return(rpcc_get_first());
}
int aget_prev(int val)
{
	return(rpcc_get_prev(val));
}
int aget_next(int val)
{
	return(rpcc_get_next(val));
}
int aget_last(int val)
{
	return(rpcc_get_last(val));
}
int aget_fact(int a,int b,int c)
{
	return(rpcc_get_fact(a,b,c));
}
