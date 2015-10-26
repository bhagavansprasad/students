#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

typedef struct open_t
{
	char filename[MAX_FILENAME_LEN+1];
	int flag;
	int mode;
}aopen_data;

typedef struct read_t
{
	int fdr;
	char *buffr;
	int countr;
}aread_data;

typedef struct write_t
{
	int fdw;
	char *buffw;
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



