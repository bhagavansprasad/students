struct open
{
	char pathname[200];
	int mode;
	int flags;
};

struct read
{
	int fd;
	char buf[200];
	int count;
};

struct write
{
	int fd;
	char buf[200];
	int count;
};

struct lseek
{
	int fd;
	off_t offset;
	int whence;
};

struct close
{
	int fd;
};

union data
{
struct open op;
struct read rd;
struct write wr;
struct lseek sk;
struct close cls;
};

struct fopdata  
{
int operation;
union data t;
};
