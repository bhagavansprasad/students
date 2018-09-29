#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_READ_LEN 100

typedef struct open_t
{
	char filename[MAX_FILENAME_LEN+1];
	int flag;
	int mode;
}aopen_data;

typedef struct read_t
{
	int fdr;
	char buffr[MAX_READ_LEN];
	int countr;
}aread_data;

typedef struct write_t
{
	int fdw;
	char buffw[MAX_READ_LEN];
	int countw;
}awrite_data;

typedef struct lseek_t
{
	int fds;
	int offset;
	int whence;
}alseek_data;

typedef struct close_t
{
	int fdc;	
}aclose_data;

typedef struct uds
{
	int status;
	union ust
	{
        aopen_data aopen;
        aread_data aread;
        awrite_data awrite;
        alseek_data alseek;
        aclose_data aclose;
	}aust;
}auds;

typedef struct open_s
{
	int o_fd;
	int o_errno;
}sopen;

typedef struct read_s
{
	char buff[MAX_READ_LEN];
	int rdval;
	int r_errno;
}sread;

typedef struct write_s
{
	int wrval;
	int w_errno;
}swrite;

typedef struct lseek_s
{
	int l_fd;
	int l_errno;
}slseek;

typedef struct close_s
{
	int c_retval;
	int c_errno;
}sclose;

typedef struct suds
{
	int type;
	union sust
	{
		sopen rp_open;
		sread rp_read;
		swrite rp_write;
		slseek rp_lseek;
		sclose rp_close;
	}asust;
}asuds;

typedef struct dumpstruct
{
	int type;
	union servclnt
	{
		auds *st_client;
		asuds *st_server;
	}var;
}st_dump;
