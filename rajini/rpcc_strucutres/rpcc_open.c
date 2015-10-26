#include "stdio.h"
#include "fcntl.h"
#include "rpccfop1.h"
#include "struct.h"
#include "string.h"
int rpcc_open(char * p,int mode,int flags)
{
	int fd;
    
	struct open_data odata;
	
	strcpy(odata.p,p);
	
	odata.mode=mode;
	
	odata.flags=flags;
	
	fd=rpcc_fop(1,&odata,NULL,NULL,NULL,NULL);
	
	return fd;
}

int rpcc_read(int fd,char * buff,int len)
{
	int r;
	
	struct read_data rdata;
	
	rdata.fd=fd;
	
	strcpy(rdata.buff,buff);
	
	rdata.len=len;

	r=rpcc_fop(2,NULL,&rdata,NULL,NULL,NULL);
	
	return r;
}

int rpcc_write(int fd1,char * buff,int len)
{
	int w;
	
	
	struct write_data wdata;
	
	wdata.fd=fd1;
    
	strcpy(wdata.buff,buff);
	
	wdata.len=len;

	w=rpcc_fop(3,NULL,NULL,&wdata,NULL,NULL);
	
	return w;
}

off_t rpcc_lseek(int fd,off_t offset,int whence)
{
	off_t f; 
	
	struct lseek_data sdata;
	
	sdata.fd=fd;
	
	sdata.offset=offset;
	
    sdata.whence=whence;

	f=rpcc_fop(4,NULL,NULL,NULL,&sdata,NULL);
	
	return f;
}

int rpcc_close(int fd)
{
	int e;
	
	struct close_data cdata;
	
	cdata.fd=fd;

	e=rpcc_fop(5,NULL,NULL,NULL,NULL,&cdata);
	
	return e;
}

