typedef struct opn_data_t
{
	char fname[100];
	int mode;
	int fd;
	int retval;
}opn_data;

typedef struct rdwt_data_t
{
	int fd;
	char buffer[1024];
	int count;
	int retval;
}rdwt_data;

typedef struct seek_data_t
{
	int fd;
	int offset;
	int whence;
	int newoffset;
	int retval;
}seek_data;

typedef struct cls_data_t
{
	int fd;
}cls_data;

typedef union fop_data_union_t
{
	opn_data opn;
	rdwt_data rdwt;
	seek_data seek;
	cls_data cls;
}fop_data_union;

typedef struct fop_data_t
{
	int cmd;
	fop_data_union udata;
}fop_data;


#define FILE_OPEN 1
#define FILE_READ 2
#define FILE_WRITE 3
#define FILE_SEEK 4
#define FILE_CLOSE 5

#define SRVR_IPADDR "127.0.0.1"
#define SRVR_PORT 8888 

#if 0
enum fop_cmds_t
{
	FILE_OPEN = 1,
	FILE_READ = 2,
	FILE_WRITE = 3,
	FILE_SEEK=4,
	FILE_CLOSE=5
}fop_cmds;
#endif

int init_communication_channel(char *ip_addr, int port);
