#include "stdio.h"
#include "fcntl.h"
#include "rpcc_fope.h"
#include "struct.h"
#include "string.h"
#define OPEN_REQ 1
#define READ_REQ 2
#define WRITE_REQ 3
#define LSEEK_REQ 4
#define CLOSE_REQ 5

int rpcc_open(char *fname,int flags,int mode)
{
	int fd;
	struct open_data op;
	strcpy(op.fname,fname);
	op.mode = mode;
	op.flags = flags;
	fd = rpcc_fope(OPEN_REQ,&op,NULL,NULL,NULL,NULL);
	return fd;
}

int rpcc_read(int fd,char *buff,int len)
{
	int r;
	struct read_data pr;
	pr.fd = fd;
	strcpy(pr.buff,buff);
	pr.len = len;
	r = rpcc_fope(READ_REQ,NULL,&pr,NULL,NULL,NULL);
	return r;
}

int rpcc_write(int fd,char *buff,int len )
{
	int w;
	struct write_data pw;
	pw.fd = fd;
	strcpy(pw.buff,buff);
	pw.len = len;
	w = rpcc_fope(WRITE_REQ,NULL,NULL,&pw,NULL,NULL);
	return w;
}

off_t rpcc_lseek(int fd,off_t k,int num)
{
	int l;
	struct lseek_data pseek;
	pseek.fd = fd;
	pseek.k = k;
	pseek.num = num;
	l = rpcc_fope(LSEEK_REQ,NULL,NULL,NULL,&pseek,NULL);
	return l;
}

int rpcc_close(int fd)
{
	int t;
	struct close_data pcls;
	pcls.fd = fd;
	t = rpcc_fope(CLOSE_REQ,NULL,NULL,NULL,NULL,&pcls);
	return t;
}
