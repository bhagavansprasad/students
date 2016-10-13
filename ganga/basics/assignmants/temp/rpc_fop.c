#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "rpc_fop.h"
#define open  1
#define read  2
#define write 3
#define lseek 4
#define close 5


int rpc_foperations(int fd, int retval, int new_offset, int cd)
{
	int i, fd1 = -1, fd2 = -1 ;

	switch (i)
	{	
		case 1:

			fd = open(fname, mode, flags);

			return fd;

			break;	

		case 2:

			retval = read(fd1, buff, 10);

			return retval;

			break;

		case 3:	

			retval = write(fd2, buff, 10);

			return retval;

			break;


		case 4:

			new_offset = lseek(fd, -10, SEEK_END);

			return new_offset;

			break;

		case 5:

			cd  = close(fd);

			return close(fd);

			break;

		default:

			printf("there is no file:");

			break;


	}
}
