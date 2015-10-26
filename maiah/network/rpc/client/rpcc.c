#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "arpc.h"
#include "rpcc_fop.h"
#include "rpcc.h"

int rpcc_open(char *fname, int mode, int flags)
{
	int retval = 0;
	fop_data_req client_data;
	fop_data_rep server_data;

	client_data->operation = OPEN_REQUEST;
	strcpy(client_data->data.odata.filename, fname);
	client_data->data.odata.mode = mode;
	client_data->data.odata.flags = flags;

	retval = rpcc_fop(&client_data);

#if 0
	rrval=rpcc_recv_data(&server_data);
	printf("-----> in rpcc client rrval is : %d\n",rrval);
	printf("----> in rpcc fd is: %d\n",server_data.sudata.sodata.fd);
	return (server_data.sudata.sodata.fd);
#endif

	return retval;
}

#if 0
int rpcc_read(int fd, char *buff,int len)
{
	int retval=0;
	fop_data_req client_data;
	fop_data_rep server_data;

	client_data.operation=READ_REQUEST;
	client_data.data.rdata.fd=fd;
	strcpy(client_data.data.rdata.buff,buff);
	client_data.data.rdata.len=len;
	retval=rpcc_fop(&client_data);
	rrval=rpcc_recv_data(&server_data);
	strcpy(buff,server_data.sudata.srdata.buff);
	buff[server_data.sudata.srdata.retval]='\0';
	printf("---->in rpcc buff is : %s\n",buff);
	return (server_data.sudata.srdata.retval); 
}

int rpcc_write(int fd, char *buff, int len)
{
	int retval=0;
	fop_data_req client_data;
	fop_data_rep server_data;

	client_data.operation=WRITE_REQUEST;
	client_data.data.wdata.fd=fd;
	strcpy(client_data.data.wdata.buff,buff);
	client_data.data.wdata.len=len;
	retval=rpcc_fop(&client_data);
	rrval=rpcc_recv_data(&server_data);
	return (server_data.sudata.swdata.retval);
}

off_t rpcc_lseek(int fd,off_t offset,int whence)
{
	int retval=0;
	fop_data_req client_data;
	fop_data_rep server_data;
	
	client_data.operation=LSEEK_REQUEST;
	client_data.data.seekdata.fd=fd;
	client_data.data.seekdata.offset=offset;
	client_data.data.seekdata.whence=whence;
	retval=rpcc_fop(&client_data);
	rrval=rpcc_recv_data(&server_data);
	return (server_data.sudata.sseekdata.offset);

}

int rpcc_close(int fd)
{
	int retval=0;
	fop_data_req client_data;
	fop_data_rep server_data;
	
	client_data.operation=CLOSE_REQUEST;
	client_data.data.cdata.fd=fd;
	retval=rpcc_fop(&client_data);
	rrval=rpcc_recv_data(&server_data);
	return (server_data.sudata.scdata.fd);

}
#endif
