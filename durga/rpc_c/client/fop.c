#include "rpc_c.h"
#include <stdio.h>
#include <stdlib.h>
/*function for aopen*/

int aopen( char *pathname, int mode, int flag)
{
	int fd;
	fd = rpc_open( pathname,mode, flag);
	printf("----->>>open in fop.c return value: %d\n",fd);
	if(fd == -1)
	{
		printf("----->>>open in fop.c failed\n");
		exit(1);
		
	}
	return(fd);
}
/*function for read*/

int aread( int fd, char *buf, int len)
{
	return (rpc_read( fd, buf, len));
//	printf("------->>> read return value in fop.c r :%d\n",r);
}

/*function for write*/

int awrite( int fd, char *buf, int len)
{
	return (rpc_write( fd, buf, len));
//	printf("------->>> write return value in fop.c w :%d\n",r);
}

/*function for close*/

int aclose( int fd)
{
    return (rpc_close( fd));
//	printf("------->>> close return value in fop.c r :%d\n",r);
}


