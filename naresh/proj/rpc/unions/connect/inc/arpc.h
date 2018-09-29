#define SRVR_PORT 7777

enum efope_type
{
	OPEN_REQUEST = 1,
	OPEN_REPLY,
 	READ_REQUEST,
 	READ_REPLY, 
 	WRITE_REQUEST,
 	WRITE_REPLY,
 	CLOSE_REQUEST,
	CLOSE_REPLY,
 	LSEEK_REQUEST,
 	LSEEK_REPLY
};

typedef struct open_data_req
{
	char fname[128];
	int mode;
	int flags;
}odata_req;

typedef struct open_data_rep
{
	int fd;
	int erno;
}odata_rep;

typedef struct read_data_req
{
	int rfd;
	char rbuff[256];
	int len;
}rdata_req;

typedef struct read_data_rep
{
	int rfd;
	char rbuff[256];
	int erno;
}rdata_rep;

typedef struct write_data_req
{
	int wfd;
	char wbuff[256];
	int rd;
}wdata_req;

typedef struct write_data_rep
{
	int wfd;
	int erno;
}wdata_rep;

typedef struct lseek_data_req 
{
	int rfd;
	int offset;
	int whence;
}ldata_req;

typedef struct lseek_data_rep
{
	//int rfd;
	int offset;
	//int whence;
	int erno;
}ldata_rep;

typedef struct close_data_req 
{
	int fd;
}cdata_req;

typedef struct close_data_rep
{
	int fd;
}cdata_rep;

union all_data 
{
	 odata_req odata;
	 rdata_req rdata;
	 wdata_req wdata;
	 ldata_req sdata;
	 cdata_req cdata;
};

union ali_data
{
	 odata_rep sodata;
	 rdata_rep srdata;
	 wdata_rep swdata;
	 ldata_rep sldata;
	 cdata_rep scdata;
};

typedef struct fop_data_t
{
  union all_data das;
  int fope;
}fopdata_req;

typedef struct fop_data_s
{
	union ali_data sdas;
	int fope;
}fopdata_rep;
