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
};
union all_data
{
	struct open_data odata;
	struct read_data rdata;
	struct write_data wdata;
	struct lseek_data ldata;
	struct close_data cdata;
};

typedef struct fopdata_t
{
	union all_data das;
	int fope;
}fopdata;
