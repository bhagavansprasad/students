#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "rpcc_fop.h"
#include "commondefs.h"
#include "structure1.h"
#include <string.h>
int rpcc_open(const char *pathname, int flags, mode_t mode)
{
	int fd;
	uss.y = open_req;
	strcpy(uss.us.sopen.pathname, pathname);
	uss.us.sopen.flags = flags;
	uss.us.sopen.mode = mode;
	fd = rpcc_fop(&uss);
	return fd;
}

ssize_t rpcc_read(int fd, void *buf, size_t count)
{
	int fd1;
	uss.y = read_req;
	uss.us.sread.fd = fd;
	//strcpy(sread.buf, buf);
	uss.us.sread.count = count;
	fd1 = rpcc_fop(&uss);
	strcpy(buf,uss.us.sread.buf);
	return fd1;
}

ssize_t rpcc_write(int fd,const void *buf, size_t count)
{
	int i;
	uss.y = write_req;
	uss.us.swrite.fd = fd;
	strcpy(uss.us.swrite.buf, buf);
	printf("IN rpcc_write buf is %s\n", buf);
	uss.us.swrite.count = count;
	i = rpcc_fop(&uss);
	return i;
}

off_t rpcc_lseek(int fd, off_t offset, int whence)
{
	int i;
	uss.y = lseek_req;
	uss.us.slseek.fd = fd;
	uss.us.slseek.offset= offset;
	uss.us.slseek.whence = whence;
	i = rpcc_fop(&uss);
	return i;
}

int rpcc_close(int fd)
{
	int i;
	uss.y = close_req;
	uss.us.sclose.fd = fd;
	i = rpcc_fop(&uss);
	return i;
}
