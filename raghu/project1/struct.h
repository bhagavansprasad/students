struct open
{
	char fn[100];
	int flag;
	int mode;
};
struct read
{
	int fp;
	char buff[100];
	int len;
};
struct write
{
	int fp;
	char buff[100];
	int len;
};
struct close
{
	int fn;
};
union rpc
{
	struct open o;
	struct read r;
	struct write w;
	struct close c;
};
struct rpcc
{
	int op;
	union rpc u;
};


