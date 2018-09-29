int rpcc_open(char *,int,int);
int rpcc_read(int,char *,int);
int rpcc_write(int,char *,int);
off_t rpcc_lseek(int,off_t,int);
int rpcc_close(int);

struct open_data
{
	char fname[128];
	int mode;
	int flags;
};

struct read_data
{
	int fd;
	char buff[128];
	int len;
};

struct write_data
{
	int fd;
	char buff[128];
	int len;
};

struct lseek_data
{
	int fd;
	off_t k;
	int num;
};

struct close_data
{
	int fd;
}
