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
	int rd;
};

struct lseek_data 
{
	int rfd;
	int offset;
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

typedef struct fopdata_t
{
  union all_data das;
  int fope;
}fopdata;
