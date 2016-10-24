
#define CRPC_OPEN_REQ  1
#define CRPC_READ_REQ  2
#define CRPC_WRITE_REQ 3
#define CRPC_LSEEK_REQ 4
#define CRPC_CLOSE_REQ 5


struct open_st
{
	char fname[256];
	int mode;
	int flags;
}odata;

struct read_st
{
	int fd;
	char buff[256];
	int size;
}rdata;

struct write_st
{
	int fd;
	char buff[256];
	int size;
}wdata;

struct lseek_st
{
	int fd;
	int off_set;
	int whence;
}sdata;

struct close_st
{
	int fd;
}cdata;


union rpcfop_un
{
	struct open_st  odata;
	struct read_st  rdata;
	struct write_st wdata;
	struct lseek_st sdata;
	struct close_st cdata;
}udata;

struct rpc_fop_data
{
	int operation;
	union rpcfop_un udata;
};

int rpc_foperations(struct rpc_fop_data *prpcdata);
