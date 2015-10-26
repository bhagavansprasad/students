int rpcc_open(char *,int,int);
int rpcc_read(int,char *,int);
int rpcc_write(int,char *,int);
off_t rpcc_lseek(int,off_t,int);
int rpcc_close(int);

struct open
{
	char fname[100];
	int mode;
	int flag;
};

struct read
{
	int fd;
	char buff[200];
	int len;
};

struct write
{
	int fd;
	char buff[200];
	int len;
};

struct lseek
{
	int fd;
	int len;
	int whence;
};

struct close
{
	int fd;
};
