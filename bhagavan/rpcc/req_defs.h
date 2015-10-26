#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
struct open
{
	char pathname[100];
	int flag;
	int mode;
};

struct read
{
	int fd1;
	char buff[100];
	int count;
};

struct write
{
	int fd2;
	char buff[100];
	int count;
};

struct close
{
	int fd;
};

union uns
{
	struct open a_open_d1;
	struct read a_read_d2;
	struct write a_write_d3;
	struct close a_close_d4;
};

struct fds
{
	int type;
	union uns a_uns;
};

