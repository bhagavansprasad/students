#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "rpc_fop.h"
#define OPEN  1
#define READ  2
#define WRITE 3
#define LSEEK 4
#define CLOSE 5


int rpc_foperations(int fd, int retval, int new_offset, int cd)
{
	int i, fd1 = -1, fd2 = -1 ;

	switch (i)
	{	
		case OPEN:
			//fd = open(fname, mode, flags);
			return fd;

		case READ:
			//retval = read(fd1, buff, 10);
			return retval;

		case WRITE:	
			//retval = write(fd2, buff, 10);
			return retval;

		case LSEEK:
			//new_offset = lseek(fd, -10, SEEK_END);
			return new_offset;

		case CLOSE:
			return close(fd);

		default:
			printf("there is no file:");
			break;
	}
}
