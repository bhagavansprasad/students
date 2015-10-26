#include "stdio.h"
#include "fcntl.h"
#include "rpcc_fope.h"
#include "struct.h"
#include "string.h"
#define OPEN 1
#define READ 2
#define WRITE 3
#define LSEEK 4
#define CLOSE 5

int rpcc_open(char *fname,int mode,int flag)
{
	int fd;
	struct open op;

	printf("%d\n %s\n %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("-->fname :%s, mode :%d, flag :%d\n",fname,mode,flag);

	strcpy(op.fname,fname);
	op.mode = mode;
	op.flag = flag;
	
	fd = rpcc_fop(OPEN,&op,NULL,NULL,NULL,NULL);
	printf("--> return fd :%d\n",fd);

	return fd;
}

int rpcc_read(int fd,char *buff,int len)
{
	int r;
	struct read rd;
	rd.fd = fd;
	strcpy(rd.buff,buff);
	rd.len = len;

	r = rpcc_fop(READ,NULL,&rd,NULL,NULL,NULL);
	strcpy(buff,rd.buff);
		
	return r;
}

int rpcc_write(int fd,char *buff,int len)
{
	int w;
	struct write wtr;
	wtr.fd = fd;
	strcpy(wtr.buff,buff);
	wtr.len = len;

	w = rpcc_fop(WRITE,NULL,NULL,&wtr,NULL,NULL);

	return w;
}

off_t rpcc_lseek(int fd,off_t k,int whence )
{
	int l;
	struct lseek lsk;
	lsk.fd = fd;
	lsk.k = k;
	lsk.whence=whence;

	l = rpcc_fop(LSEEK,NULL,NULL,NULL,&lsk,NULL);
	
	return l;
}

int rpcc_close(int fd)
{
	int t;
	struct close cls;
	cls.fd = fd;

	t = rpcc_fop(CLOSE,NULL,NULL,NULL,NULL,&cls);
	
	return t;
}
