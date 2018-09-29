#include "rpcstructs.h"

int rpcs_open(auds d2)
{
	int fd = open(d2.aust.aopen.filename, d2.aust.aopen.flag, d2.aust.aopen.mode);
	
	return fd;
}

int rpcs_read(auds d2)
{
	int rdval = read(d2.aust.aread.fdr, d2.aust.aread.buffr, d2.aust.aread.countr);
	
	return rdval;
}

int rpcs_write(auds d2)
{
	int wrval = write(d2.aust.awrite.fdw, d2.aust.awrite.buffw, d2.aust.awrite.countw);
	
	return wrval;
}

int rpcs_lseek(auds d2)
{
	int offstval = lseek(d2.aust.alseek.fds, d2.aust.alseek.offset, d2.aust.alseek.whence);

	return offstval;
}

int rpcs_close(auds d2)
{
	int retval = close(d2.aust.aclose.fdc);
	
	return retval;
}


