#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int rpc_open(char *,int,int);
int rpc_read(int ,char *,int);
int rpc_write(int,char *,int);
int rpc_close(int);
struct open_a
{
	char s[100];
	int flags;
	int mode;
};
struct read_r
{
	int t;
	char buff[100];
	int l;
};
struct write_w
{
	int t1;
	char buff[100];
	int rval;
};
struct close_c
{
 int t1;
 };
union rpcc_fop
{
	struct open_a o;
	struct read_r r;
	struct write_w w;
	struct close_c c;
};
struct rpcc 
{
	int op; 
	union rpcc_fop u;
};


