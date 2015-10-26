struct open_st
{
	char fd[100];
	int flag;
	int mode;
};

struct read_st
{
	int fp;
	char buff[100];
	int len;
};

struct write_st
{
	int fp;
	char buff[100];
	int len;
};

struct close_st
{
	int fd;
};

union rpc
{
	struct open_st o;
	struct read_st r;
	struct write_st w;
	struct close_st c;
};

struct rpcc
{
	int op;
	union rpc u;
};


int rpc_open(char *fn,int flag, int mode);
int rpc_read(int fn,char *buff,int len);
int rpc_write(int fn,char *buff,int len);
int rpc_close(int fn);
