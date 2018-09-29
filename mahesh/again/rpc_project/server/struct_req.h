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
struct A_get_prev
{
	int val;
};
struct A_get_next
{
	int val;
};
struct A_get_fact
{
	int val1;
	int val2;
	int val3;
};
union UNI
{
	struct A_open a_open;
	struct A_read a_read;
	struct A_write a_write;
	struct A_lseek a_lseek;
	struct A_close a_close;
	struct A_get_prev a_prev;
	struct A_get_next a_next;
	struct A_get_fact a_fact;
};
struct final
{
	int op;
	union UNI uni;
};
