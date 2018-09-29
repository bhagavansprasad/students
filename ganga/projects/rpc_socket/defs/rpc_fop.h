#define CRPC_OPEN_REQ  1
#define CRPC_READ_REQ  2
#define CRPC_WRITE_REQ 3
#define CRPC_LSEEK_REQ 4
#define CRPC_CLOSE_REQ 5

#define CRPC_OPEN_REQ_REPLY   6
#define CRPC_READ_REQ_REPLY   7
#define CRPC_WRITE_REQ_REPLY  8
#define CRPC_LSEEK_REQ_REPLY  9
#define CRPC_CLOSE_REQ_REPLY 10

struct open_st
{
	char fname[256];
	int mode;
	int flags;
};

struct open_st_reply
{
	int fd;
};

struct read_st
{
	int fd;
	char buff[256];
	int size;
};

struct read_st_reply
{
	int retval;
	char buff[256];
};

struct write_st
{
	int fd;
	char buff[256];
	int size;
};

struct write_st_reply
{
	int retval;
};

struct lseek_st
{
	int fd;
	int off_set;
	int whence;
};

struct lseek_st_reply
{
	int new_off_set;
};

struct close_st
{
	int fd;
};

struct close_st_reply
{
	int fd;
};

union rpcfop_un
{
	struct open_st  odata;
	struct read_st  rdata;
	struct write_st wdata;
	struct lseek_st sdata;
	struct close_st cdata;
};

union rpcfop_un_reply
{
	struct open_st_reply  oreply;
	struct read_st_reply  rreply;
	struct write_st_reply wreply;
	struct lseek_st_reply sreply;
	struct close_st_reply creply;
};

struct rpc_fop_data
{
	int operation;
	union rpcfop_un udata;
};

struct rpc_fop_data_reply
{
	int operation;
	union rpcfop_un_reply ureply;
};

int rpc_foperations(struct rpc_fop_data *prpcdata);
//int rpc_foperations(struct rpc_fop_data *prpcdata, struct rpc_fop_data_reply *reply);
