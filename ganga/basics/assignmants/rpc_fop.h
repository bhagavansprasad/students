#define CRPC_OPEN_REQ  1
#define CRPC_READ_REQ  2
#define CRPC_WRITE_REQ 3
#define CRPC_LSEEK_REQ 4
#define CRPC_CLOSE_REQ 5

//int rpc_foperations(int operation, char *fname, int mode, int flags, int fd, char *buff, int size, int whence);

//int rpc_foperations(int operation, struct open_st *pop_data, struct rw_st *prd_data, struct rw_st *pwd_data, struct lseek_st *pld_data, struct close_st *pcl_data);

int rpc_foperations(int operation, union rpcfop_un *pun_data );

struct open_st
{
	char fname[256];
	int mode;
	int flags;
};

struct rw_st
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

//int rpc_foperations(int operation , union rpc_fop_un *pun_data) ;

union rpcfop_un
{
	struct open_st  odata;
	struct read_st  rdata;
	struct write_st wdata;
	struct lseek_st sdata;
	struct close_st cdata
};

struct rpc_fop_data
{
	//fd=rpc_foperations(CRPC_OPEN_REQ, &op_data, NULL, NULL, NULL, NULL);
	int operation;
	union rpcfop_un udata;
};


