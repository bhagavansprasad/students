struct open
{
	const char *pathname[50];
	int flags;
	mode_t mode;
}sopen;

struct read
{
	int fd;
	void *buf[500];
	size_t count;
}sread;

struct write
{
	int fd;
	const void *buf[500];
	int count;
}swrite;

struct lseek
{
	int fd;
	off_t offset;
	int whence;
}slseek;

struct close
{
	int fd;
}sclose;


union s
{
struct open sopen;
struct read sread;
struct write swrite;
struct lseek slseek;
struct close sclose;
}us;


struct u
{
int y;
union s us;
}uss;
