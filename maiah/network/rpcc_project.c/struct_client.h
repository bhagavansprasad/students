struct open_data
{
	char filename[10];
	int mode;
	int flags;
};

struct read_data
{
	int fd;
	char buff[100];
	int len;
};

struct write_data
{
	int fd;
	char buff[100];
	int len;
};

struct close_data
{
	int fd;
};

struct lseek_data
{
	int fd;
	int offset;
	int whence;
};


union fope_data
{
	struct open_data odata;
	struct read_data rdata;
	struct write_data wdata;
	struct close_data cdata;
	struct lseek_data seekdata;
};

typedef struct fop_data_t
{
	int operation;
	union fope_data data;
}fop_data;
