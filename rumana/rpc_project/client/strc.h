struct open
{
	char p[10];
	int m;
	int f;
};
struct read
{
	int m;
	char b[100];
	int f;
};
struct write
{
	int m;
	char b[100];
	int f;
};
struct close
{
	int m;
};
union tag
{
	struct open o;
	struct read r;
	struct write w;
	struct close c;
};
struct ch
{
	union tag t;
	int flag;
};
