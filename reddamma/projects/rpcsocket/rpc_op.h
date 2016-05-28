int rpc_open(char * s,int mode,int flags);
int rpc_read(int t,char *buff,int l);
int rpc_close(int t);

struct open_data
{
	char s[100];
	int mode;
	int flags;
};

struct read_data
{
	int t;
	char buff[200];
	int l;
};

struct close_data
{
	int t;
};
