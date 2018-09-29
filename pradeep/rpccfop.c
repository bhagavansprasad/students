#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fop.h"
#include "struct.h"
#include "union.h"
int rpccopen(const char *pathname, int flags, mode_t mode)
{
	int fd=0;
	union rpcc u1;
	struct sopen o1;
	strcpy(u1.o1.pathname,pathname);
	u1.o1.flags=flags;
	u1.o1.mode=mode;
	fd=rpcc_fop(1,&o1);
	return fd;
}
ssize_t rpccread(int fd, void *buf, size_t count)
{
	int r=0;
	union rpcc u1;
	struct sread r1;
	u1.r1.fd=fd;
	strcpy(buf,u1.r1.buf);
	u1.r1.count=count;
	r=rpcc_fop(2,&r1);
	return r;
}
ssize_t rpccwrite(int fd, void *buf, size_t count)
{
	int w=0;
	union rpcc u1;
	struct swrite w1;
	u1.w1.fd=fd;
	strcpy(buf,u1.w1.buf);
	u1.w1.count=count;
	w=rpcc_fop(3,&w1);
	return w;
}
off_t rpcclseek(int fd, off_t offset, int whence)
{
	int l=0;
	union rpcc u1;
	struct slseek l1;
	u1.l1.fd=fd;
	u1.l1.offset=offset;
	u1.l1.whence=whence;
	l=rpcc_fop(4,&l1);
	return l;
}
int rpccclose(int fd)
{
	int c=0;
	union rpcc u1;
	struct sclose c1;
	u1.c1.fd=fd;
	c=rpcc_fop(5,&c1);
	return c;
}
