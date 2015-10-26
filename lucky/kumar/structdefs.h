struct opendata
{
	char pathname[100];
	int flags;
	int mode;
};
struct readdata
{
	int fd;
	char buf[100];
	int  count;
};
struct writedata
{
	int fd;
	char buf[100];
	int  count;
};
struct lseekdata
{
	int fd;
	off_t offset;
	int whence;
};
struct closedata
{
	int fd;
};	

union rpc
{
struct opendata o1;
struct readdata r1;
struct writedata w1;
struct lseekdata l1;
struct closedata c1;
};
