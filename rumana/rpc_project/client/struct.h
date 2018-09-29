struct sopen
{
	int fd;
	int errno;
};
struct sread
{
	int retval;
	char buf[100];
};
struct swrite
{
	int retval;
	int errno;
};
struct sclose
{
	int retval;
	int errno;
};
union time
{
	struct sopen o;
	struct sread r;
	struct swrite w;
	struct sclose c;
};
struct server
{
	union time ts;
	int  node;
};
