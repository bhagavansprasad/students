#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpc_fop.h"

//int rpc_foperations(int operation, char *fname, int mode, int flags, int fd, char *buff, int size, int whence)

//int rpc_foperations(int operation, struct open_st *pop_data, struct rw_st *prd_data, struct rw_st *pwd_data, struct lseek_st *pld_data, struct close_st *pcl_data)

int rpc_foperations(int operation , union rpcfop_un *pun_data );
{
	int retval = -1 ;
	int new_offset = -1 ;
	int fd = -1 ;

	switch (operation)
	{	
		case CRPC_OPEN_REQ:
			fd = open(pun_data->fname, pun_data->mode, pun_data->flags);

			return fd;

		case CRPC_READ_REQ:
			retval = read(pun_data->fd, pun_data->buff, pun_data->size);

			return retval;

		case CRPC_WRITE_REQ:	
			retval = write(pun_data->fd, pun_data->buff, pun_data->size);

			return retval;

		case CRPC_LSEEK_REQ:
			new_offset = lseek(pun_data->fd, pun_data->off_set, pun_data->whence);

			return new_offset;

		case CRPC_CLOSE_REQ:
			return close(fd);

		default:
			printf("there is no file:");
			break;
	}
}
