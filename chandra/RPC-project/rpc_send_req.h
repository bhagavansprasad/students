struct reply_open
{
	int rfd;
	int errno;
};

struct reply_read
{
	int rfd;
	char buff[100];
	int errno;
};

struct reply_write
{
	int wfd;
	int errno;
};

struct reply_lseek
{
int rfd;
int errno;
};

struct reply_close
{	
	int wfd;
	int errno;
};

union rdata
{
	struct reply_open ro;
	struct reply_read rr;
	struct reply_write rw;
	struct reply_lseek rl;
	struct reply_close rc;
};

struct rpcs
{
	int rop;
	union rdata ru;
};

