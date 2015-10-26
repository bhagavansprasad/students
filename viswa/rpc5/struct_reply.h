struct reply_open
{
	int fd;
	int errono;
};


struct reply_read
{
	int fd;
	char buff[100];
	int errorno;
};


struct reply_write
{
	int fd;
	char buff[100];
	int errorno;

};


struct reply_close
{
	int fd;
};


union reply
{
struct reply_open r_ope;
struct reply_read r_rea;
struct reply_write r_wri;
struct reply_close r_clo;
};

struct  reply_final
{
union reply rey;
};
