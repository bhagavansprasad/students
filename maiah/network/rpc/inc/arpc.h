#define SRVR_PORT 6666

#define OPEN_REQUEST 1
#define READ_REQUEST 2
#define WRITE_REQUEST 3
#define LSEEK_REQUEST 4
#define CLOSE_REQUEST 5

typedef struct open_data_req_t
{
	char filename[100];
	int mode;
	int flags;
}odata_req;

typedef struct open_data_rep_t
{
	int fd;
	int erno;
}odata_rep;

typedef struct read_data_req_t
{
	int fd;
	char buff[100];
	int len;
}rdata_req;

typedef struct read_data_rep_t
{
	int retval;
	char buff[100];
	int erno;
}rdata_rep;

typedef struct write_data_req_t
{
	int fd;
	char buff[100];
	int len;
}wdata_req;

typedef struct write_data_rep_t
{
	int retval;
	int erno;
}wdata_rep;

typedef struct close_data_req_t
{
	int fd;
}cdata_req;
typedef struct close_data_rep_t
{
	int fd;
}cdata_rep;

typedef struct lseek_data_req_t
{
	int fd;
	int offset;
	int whence;
}seekdata_req;

typedef struct lseek_data_rep_t
{
	//int fd;
	int offset;
	//int whence;
	int erno;
}seekdata_rep;

union fope_data
{
	 odata_req odata;
	 rdata_req rdata;
	 wdata_req wdata;
	 cdata_req cdata;
	 seekdata_req seekdata;

};

union fop_data
{
	 odata_rep sodata;
	 rdata_rep srdata;
	 wdata_rep swdata;
	 cdata_rep scdata;
	 seekdata_rep sseekdata;
};

typedef struct fop_data_t
{
	int operation;
	union fope_data data;
}fop_data_req;

typedef struct fop_data_s
{
	int operation;
	union fop_data sudata;
}fop_data_rep;
