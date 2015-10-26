#include "rpcstructs.h"

int rpc_fop(aopen_data *popen, aread_data *pread, awrite_data *pwrite, alseek_data *plseek, aclose_data *pclose);

int rpc_open(char *filename, int flag, int mode)
{
	aopen_data opend;
	int fd = -1;

	strcpy(opend.filename, filename);
	opend.flag = flag;
	opend.mode = mode;
	
	fd = rpc_fop(&opend, NULL, NULL, NULL, NULL);

	return fd;
}

int rpc_read(int fdr, char *buff, int count)
{
	aread_data readd;
	int rdval = 0;
	
	readd.fdr = fdr;
	readd.buffr = buff;
	readd.countr = count;

	rdval = rpc_fop(NULL, &readd, NULL, NULL, NULL);

	return rdval;
}

int rpc_write(int fdw, char *buff, int count)
{
	awrite_data writed;
	int wrval = 0;
	
	writed.fdw = fdw;
	writed.buffw =  buff;
	writed.countw = count;

	wrval = rpc_fop(NULL, NULL, &writed, NULL, NULL);

	return wrval;
}


int rpc_lseek(int fd, int offset, int whence)
{
	alseek_data lseekd;
	int offstval = 0;

	lseekd.fds = fd;
	lseekd.offset = offset;
	lseekd.whence = whence;
	
	offstval = rpc_fop(NULL, NULL, NULL, &lseekd, NULL);

	return offstval;
}

int rpc_close(int fd)
{
	aclose_data closed;
	int retval = 0;
	
	closed.fdc = fd;

	retval = rpc_fop(NULL, NULL, NULL, NULL, &closed);

	return retval;
}

