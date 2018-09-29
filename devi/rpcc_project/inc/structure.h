#define SRVR_PORT 6666
#define SRVR_IP "127.0.0.1"

enum eOperation_type
{
	OPEN_REQUEST = 1,
	OPEN_REPLAY,
	READ_REQUEST,
	READ_REPLAY,
	WRITE_REQUEST,
	WRITE_REPLAY,
	LSEEK_REQUEST,
	LSEEK_REPLAY,
	CLOSE_REQUEST,
	CLOSE_REPLAY
};

/* open request and replay */
typedef struct open_req
{
	char pathname[200];
	int mode;
	int flags;
}op_req;
typedef struct open_rep
{
	int fd;
	int error;
}op_rep;

/*read request and replay */

typedef struct read_req
{
	int fd;
	char buf[200];
	int count;
}rd_req;
typedef struct read_rep
{
	int rretval;
	char buf[200];
	int error;
}rd_rep;

/* write request and replay */
typedef struct write_req
{
	int fd;
	char buf[200];
	int count;
}wr_req;
typedef struct write_rep
{

	int wretval;
	int error;
}wr_rep;
/* lseek request and replay */

typedef struct lseek_req
{
	int fd;
	int offset;
	int whence;
}sk_req;
typedef struct lseek_rep
{
	int offset;
	int error;
}sk_rep;
/*close request and replay */

typedef struct close_req
{
	int fd;
}cls_req;
typedef struct close_rep
{
	int fd;
	int error;
}cls_rep;
/* all request and replay structures data */
typedef union tag_req
{
	op_req op;
	rd_req rd;
	wr_req wr;
	sk_req sk;
	cls_req cls;
}t_req;
typedef union tag_rep
{
	op_rep open;
	rd_rep read;
	wr_rep write;
	sk_rep lseek;
	cls_rep close;
}t_rep;
/* sending structure from client to server */
typedef struct fop_req 
{
	int ope;
	t_req t;
}fop_data_req;
/* recieving structure from server to client */
typedef struct fop_rep
{
	int ope;
	t_rep u;
}fop_data_rep;
