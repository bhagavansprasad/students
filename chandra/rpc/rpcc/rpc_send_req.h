
int rpc_send_req(struct rpcc *req);
int rpc_read_req(struct rpcs *reply);


/*struct reply_open
{
	int rfd;
	int err_no;
};

struct reply_read
{
	int rfd;
	char buff[100];
	//int err_no;
};

struct reply_write
{
	int wfd;
	int err_no;
};

struct reply_lseek
{
off_t l;
int err_no;
};

struct reply_close
{	
	int wfd;
	int errno;
};
union reply_data
{
	struct reply_open r_open;
	struct reply_read r_read;
	struct reply_write r_write;
	struct reply_lseek r_lseek;
	struct reply_close r_close;
};
struct rpcs
{
	int rop;
	union reply_data r_uni;
};
    */
