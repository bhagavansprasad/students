#include <sys/types.h>
#include <unistd.h>
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
struct S_lseek
{
	int rval;
	int err_no;
};
struct S_close
{
	off_t rval;
	int err_no;
};
struct S_first
{
	int rval;
};
struct S_prev
{
	int rval;
};
struct S_next
{
	int rval;
};
struct S_last
{
	int rval;
};
struct S_fact
{
	int rval;
};
union S_uni
{
	struct S_open s_open;
	struct S_read s_read;
	struct S_write s_write;
	struct S_lseek s_lseek;
	struct S_close s_close;
	struct S_first s_first;
	struct S_prev s_prev;
	struct S_next s_next;
	struct S_last s_last;
	struct S_fact s_fact;
};
struct S_final
{
	int s_op;
	union S_uni s_uni;
};
