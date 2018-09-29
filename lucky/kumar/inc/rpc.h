//All request headers
//open, read, write, close, lseek requests
// 5
//Union
//structure and uniion

//All reply headers 
//open, read, write, close, lseek replies
//5 
//union of replies
//structure and uniion


//#define  SRVR_IP "192.168.1.100"
#define  SRVR_IP "127.0.0.1"
#define SRVR_PORT 8888

#if 0
#define OPEN_REQUEST  1
#define OPEN_REPLY    2
#define READ_REQUEST  3
#define READ_REPLY    4
#define WRITE_REQUEST 5
#define WRITE_REPLY   6
#define LSEEK_REQUEST 7
#define LSEEK_REPLY   8
#define CLOSE_REQUEST 9
#define CLOSE_REPLY   10
#endif

enum eOperation_type
{
	OPEN_REQUEST = 1,
	OPEN_REPLY,
	READ_REQUEST,
	READ_REPLY,
	WRITE_REQUEST,
	WRITE_REPLY,
	LSEEK_REQUEST,
	LSEEK_REPLY,
	CLOSE_REQUEST,
	CLOSE_REPLY
};

//open req and reply
typedef struct open_data_req_t
{
	char filename[128];
	int mode;
	int flags;
}odata_req;

typedef struct open_data_rep_t
{
	int fd;
	int error;
}odata_rep;

//read req and reply
typedef struct read_data_req_t
{
	int fd;
	int len;
}rdata_req;

typedef struct read_data_rep_t
{
	int retval;
	char buff[100];
	int error;
}rdata_rep;

//read req and reply
typedef struct write_data_req_t
{
	int fd;
	char buff[256];
	int len;
}wdata_req;

typedef struct write_data_rep_t
{
	int retval;
	int error;
}wdata_rep;

//read req and reply
typedef struct close_data_req_t
{
	int fd;
}cdata_req;

typedef struct close_data_rep_t
{
	int error;
}cdata_rep;

//lseek req and reply
typedef struct lseek_data_req_t
{
	int fd;
	int offset;
	int whence;
}seekdata_req;

typedef struct lseek_data_rep_t
{
	int newoffset;
	int error;
}seekdata_rep;

//union of requests
union fope_data
{
	odata_req odata;
	rdata_req rdata;
	wdata_req wdata;
	cdata_req cdata;
	seekdata_req sdata;
};

//union of replies
union fop_data
{
	odata_rep sodata;
	rdata_rep srdata;
	wdata_rep swdata;
	cdata_rep scdata;
	seekdata_rep sseekdata;
};

//structure from client to server
typedef struct fop_data_t
{
	int operation;
	union fope_data data;
}fop_data_req;


//structure from server to client
typedef struct fop_data_s
{
	int operation;
	union fop_data sudata;
}fop_data_rep;
