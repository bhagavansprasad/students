struct reply_open
{
	int fd;
	int error_no;
};
struct reply_read
{
	int fd;
	char buff[100];
	int error_no;
};
struct reply_write
{
	int fd;
	int error_no;
};
struct reply_close
{
	int error_no;	
};

union reply_data
{
	struct reply_open ro;
	struct reply_read rr;
	struct reply_write rw;
	struct reply_close rc;
};
struct reply_final
{
	union reply_data urd;
};
