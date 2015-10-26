#include<sys/types.h>
#include<unistd.h>

struct S_open
{
	int fd;
	int err_no;
};

struct S_read
{
	int rval;
	char buff[100];
};

struct S_write
{
	int rval;
	int err_no;
};

struct S_close
{
	int rval;
	int err_no;
};

union S_uni
{
	struct S_open s_open;
	struct S_read s_read;
	struct S_write s_write;
	struct S_close s_close;
};

struct S_final
{
	int s_op;
	union S_uni s_uni;
};
