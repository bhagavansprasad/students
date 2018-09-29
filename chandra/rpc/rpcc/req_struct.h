struct open_data
{
	char fn[100];
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
off_t l;
int pos;
};

struct close_data
{
	int wfd;
};

union data
{
	struct open_data a_open;
	struct read_data a_read;
	struct write_data a_write;
	struct lseek_data a_lseek;
	struct close_data a_close;
};

struct rpcc
{
	int op;
	union data uni;
};

/*int rpc_open( char *fn, int flags, int mode);
int rpc_read( int rfd, char *buff, int len);
int rpc_write( int wfd, char *buff, int rretval);
int rpc_close(int wfd);
int rpcc_fop(struct rpcc *req); */

