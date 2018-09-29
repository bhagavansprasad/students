struct open_data
{
	char rfd[100];
	int flags;
	int mode;
};

struct read_data
{
    int rfd;
	char buff[100];
	int len;
};

struct write_data
{
    int wfd;
	char buff[100];
	int rretval;
};

struct lseek_data
{
int rfd;
off_t offset;
int whence;
};

struct close_data
{
	int wfd;
};

union col
{
	struct open_data o;
	struct read_data r;
	struct write_data w;
	struct lseek_data l;
	struct close_data c;
};

struct rpcc
{
	int op;
	union col u;
};

int rpc_open( char *rfd, int flags, int mode);
int rpc_read( int rfd, char *buff, int len);
int rpc_write( int wfd, char *buff, int rretval);
int alseek(int rfd, off_t offset, int whence);
int rpc_close(int wfd);
//int rpcc_fop(struct rpcc *data);

