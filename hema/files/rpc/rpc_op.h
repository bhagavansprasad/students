int rpc_open(char *s,int mode,int flags);
int rpc_read(int fd,char *buff,int len);
int rpc_write(int fd,char *buff,int rval);
int rpc_lseek(int fd,off_t s,int whence);
int rpc_close(int fd);

#define RPC_OPEN 1
#define RPC_READ 2
#define RPC_WRITE 3
#define RPC_LSEEK 4
#define RPC_CLOSE 5

#define RPC_OPEN_REPLY 6
#define RPC_READ_REPLY 7
#define RPC_WRITE_REPLY 8
#define RPC_LSEEK_REPLY 9
#define RPC_CLOSE_REPLY 10

struct open_data
{
	char s[100];
	int mode;
	int flags;
};

struct open_data_reply
{
	int fd;
};

struct read_data
{
	int fd;
	char buff[200];
	int len;
};

struct read_data_reply
{
	int rval;
	char buff[100];
};

struct write_data
{
	int fd;
	char buff[200];
	int rval;
};
struct write_data_reply
{
	int wval;
};
struct lseek_data
{
	int fd;
	off_t s;
	int whence;
};
struct lseek_data_reply
{
	int lval;
};
struct close_data
{
	int fd;
};
struct close_data_reply
{
	int fd;
};

typedef union ufope_t
{
	struct open_data opdata;
	struct read_data rrdata;
	struct write_data wrdata;
	struct lseek_data lsdata;
	struct close_data cldata;
}ufope;

typedef union ufope_reply_t
{
	struct open_data_reply op_reply;
	struct read_data_reply rr_reply;
	struct write_data_reply wr_reply;
	struct lseek_data_reply ls_reply;
	struct close_data_reply cl_reply;

}ufope_reply;


typedef struct fope_struct_t
{
	int operation;
	ufope udata;
}fope_struct;

typedef struct fope_str_reply
{
	int operation;
	ufope udata;
}fope_struct_reply;

