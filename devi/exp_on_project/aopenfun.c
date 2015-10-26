#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include <fcntl.h>
#include "structure.h"
ssize_t awrite(int fd,void *buf, size_t count)
{
	int fd1;
	fd1 = write(fd,buf,count);
	/*swrite.fd = fd;
	strcpy(swrite.buf,buf);
	swrite.count = count;
	fd1 = newwrite(&swrite);
	return fd1;*/
}

ssize_t aread(int fd,void *buf, size_t count)
{
	int fd1;
	//fd1 = read(fd,buf,count);
	sread.fd = fd;
	strcpy(sread.buf,buf);
	sread.count=count;
	fd1 = newread(&sread);
	return fd1;
}

int aopen(const char *pathname, int flags, mode_t mode)
{
	int fd;
	strcpy(sopen.pathname,pathname);
	sopen.flags = flags;
	sopen.mode = mode;
	fd = newopen(&sopen);
	return fd;
}

int aclose(int fd)
{
	int fd1;
	fd1 = close(fd);
	return fd1;

}

off_t alseek(int fd, off_t offset, int whence)
{
	int fd1;
	fd1 = lseek(fd,offset,whence);
	return fd1;
}


int newopen(struct open *sopen)
{
	int fd1;
	fd1 = open(sopen->pathname, sopen->flags, sopen->mode);
	return fd1;
}


ssize_t newread(struct read *sread)
{
	int fd1;
	fd1 = read(sread->fd,sread->buf,sread->count);
	return fd1;
}

/*ssize_t newwrite(struct write *swrite)
{
	int fd;
	fd = write(swrite->fd, swrite->buf, swrite->count);
	return fd;
}*/
