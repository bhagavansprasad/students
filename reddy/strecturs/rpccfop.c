#include "fcntl.h"
#include "stdio.h"
#include "rpccfope.h"
#include "string.h"
#include "rpccfop.h"
#define OPEN 1
#define READ 2
#define WRITE 3
#define LSEEK 4
#define CLOSE 5
int rpcc_open(char *p,int m,int fl)
{
	int fd;
	struct open ope;

	printf("%d\n %s\n %s\n",__LINE__,__FUNCTION__,__FILE__);
	printf("-->p :%s, m :%d, fl :%d\n",p,m,fl);

	strcpy(ope.fname,p);
	ope.mode=m;
	ope.flag=fl;
	
	fd=rpcc_fop(OPEN,&ope,NULL,NULL,NULL,NULL);
	printf("--> return fd :%d\n",fd);

	return fd;
}

int rpcc_read(int f,char *b,int l)
{
	int r;
	struct read rd;
	rd.fd=f;
	strcpy(rd.buff,b);
	rd.len=l;

	r=rpcc_fop(READ,NULL,&rd,NULL,NULL,NULL);
	strcpy(b,rd.buff);
		
	return r;
}

int rpcc_write(int f,char *b,int l)
{
	int w;
	struct write wtr;
	wtr.fd=f;
	strcpy(wtr.buff,b);
	wtr.len=l;

	w=rpcc_fop(WRITE,NULL,NULL,&wtr,NULL,NULL);

	return w;
}

off_t rpcc_lseek(int f,off_t l,int y )
{
	int ls;
	struct lseek lsk;
	lsk.fd=f;
	lsk.len=l;
	lsk.whence=y;

	ls=rpcc_fop(LSEEK,NULL,NULL,NULL,&lsk,NULL);
	
	return ls;
}

int rpcc_close(int f)
{
	int t;
	struct close cls;
	cls.fd=f;

	t=rpcc_fop(CLOSE,NULL,NULL,NULL,NULL,&cls);
	
	return t;
}
