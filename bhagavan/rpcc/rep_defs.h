#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#if 0
struct sopen
{
	char pathname[100];
	int flag;
	int mode;
};

struct sread
{
	int fd1;
	char buff[100];
	int count;
};

struct swrite
{
	int fd2;
	char buff[100];
	int count;
};

struct sclose
{
	int fd;
};

union auns
{
	struct sopen a_open_d1;
	struct sread a_read_d2;
	struct swrite a_write_d3;
	struct sclose a_close_d4;
};

struct newfds
{
	int type;
	union auns a_uns;
};

#endif
