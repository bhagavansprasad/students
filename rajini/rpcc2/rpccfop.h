int rpccopen(char *fname,int mode,int flags);
int rpccread(int rfd,char *buff,int len);
int rpccwrite(int wfd,char *buff,int len);
off_t rpcclseek(int rfd,off_t offset,int whence);
int rpccclose(int fd);

struct open_data
{
	char fname[128];
	int mode;
	int flags;
};

struct read_data
{
	int rfd;
	char rbuff[256];
	int len;
};

struct write_data
{
	int wfd;
	char wbuff[256];
	int len;
};

struct lseek_data 
{
	int rfd;
	off_t offset;
	int whence;
};

struct close_data 
{
	int fd;
};

union all_data 
{
	struct open_data odata;
	struct read_data rdata;
	struct write_data wdata;
	struct lseek_data sdata;
	struct close_data cdata;
};

struct raj
{
  union all_data das;
  int fope;
};
