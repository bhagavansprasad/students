#include "afun1.h"
aopen(char *file , int mode , int flag )
{
	return rpc_open( file , mode , flag);
}

aread(int fd , char *buff , int len)
{
	return rpc_read( fd , buff ,len);
}

awrite(int fd , char *buff ,int len)
{
	return rpc_write( fd , buff , len);
}
aclose(int fd)
{
	return rpc_close( fd );
}
