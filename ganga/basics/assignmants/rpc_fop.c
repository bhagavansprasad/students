#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpc_fop.h"

int rpc_foperations(int operation, char *fname, int mode, int flags, int fd, char *buff, int size, int whence)
{
	int retval = 0;
	int new_offset = 0;

	switch (operation)
	{	
		case CRPC_OPEN_REQ:
			fd = open(fname, mode, flags);

			return fd;

		case CRPC_READ_REQ:
			retval = read(fd, buff, size);

			return retval;

		case CRPC_WRITE_REQ:	
			retval = write(fd, buff, size);

			return retval;

		case CRPC_LSEEK_REQ:
			new_offset = lseek(fd, size, whence);

			return new_offset;

		case CRPC_CLOSE_REQ:
			return close(fd);

		default:
			printf("there is no file:");
			break;
	}
}
