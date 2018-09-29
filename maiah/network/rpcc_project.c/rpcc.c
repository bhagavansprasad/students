#include <fcntl.h>
#include <stdio.h>
#include "struct_client.h"
#include <string.h>
#include "rpcc.h"
#include "rpcc_fop.h"
#define OPEN_REQUEST 1
#define READ_REQUEST 2
#define WRITE_REQUEST 3
#define LSEEK_REQUEST 4
#define CLOSE_REQUEST 5

int rpcc_open(char *fname, int mode, int flags)
{
	fop_data client_data;
	int retval = 0;

	int rrval=-1;
	client_data.operation = OPEN_REQUEST;
	strcpy(client_data.data.odata.filename, fname);
	client_data.data.odata.mode = mode;
	client_data.data.odata.flags = flags;
	retval = rpcc_fop(&client_data);
}

int rpcc_read(int fd, char *buff,int len)
{
	int retval=0;
	fop_data client_data;

	client_data.operation=READ_REQUEST;
	client_data.data.rdata.fd=fd;
	strcpy(client_data.data.rdata.buff,buff);
	client_data.data.rdata.len=len;
	retval=rpcc_fop(&client_data);
}

int rpcc_write(int fd, char *buff, int len)
{
	fop_data client_data;
	int retval=0;

	client_data.operation=WRITE_REQUEST;
	client_data.data.wdata.fd=fd;
	strcpy(client_data.data.wdata.buff,buff);
	client_data.data.wdata.len=len;
	retval=rpcc_fop(&client_data);
}

off_t rpcc_lseek(int fd,off_t offset,int whence)
{
	fop_data client_data;
	int retval=0;
	
	client_data.operation=LSEEK_REQUEST;
	client_data.data.seekdata.fd=fd;
	client_data.data.seekdata.offset=offset;
	client_data.data.seekdata.whence=whence;
	retval=rpcc_fop(&client_data);
}

int rpcc_close(int fd)
{
	fop_data client_data;
	int retval=0;
	
	client_data.operation=CLOSE_REQUEST;
	client_data.data.cdata.fd=fd;
	retval=rpcc_fop(&client_data);
}
