#include <sys/types.h>
#include <unistd.h>
struct A_open
{
	char fn[100];
	int flags;
	int mode;
};
struct A_read
{
	int fd;
	char buff[100];
	int len;
};
struct A_write
{
	int fd;
	char buff[100];
	int rval;
};
struct A_lseek
{
	int fd;
	off_t l;
	int pos;
};
struct A_close
{
	int fd;
};
union UNI
{
	struct A_open a_open;
	struct A_read a_read;
	struct A_write a_write;
	struct A_lseek a_lseek;
	struct A_close a_close;
};
struct final
{
	int op;
	union UNI uni;
};
