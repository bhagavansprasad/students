#define CRPC_OPEN_REQ  1
#define CRPC_READ_REQ  2
#define CRPC_WRITE_REQ 3
#define CRPC_LSEEK_REQ 4
#define CRPC_CLOSE_REQ 5

//int rpc_foperations(int operation, char *fname, int mode, int flags, int fd, char *buff, int size, int whence);

int rpc_foperations(int operation, struct open_st *pop_data, struct read_st *prd_data, struct write_st *pwd_data, struct lseek_st *pld_data, struct close_st *pcl_data);

struct open_st
{
	char fname[256];
	int mode;
	int flags;
};

struct read_st
{
	int fd;
	char buff[256];
	int size;
};

struct write_st
{
	int fd;
	char buff[256];
	int size;
};

struct lseek_st
{
	int fd;
	int off_set;
	int whence;
};

struct close_st
{
	int fd;
};
