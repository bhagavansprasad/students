#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
ssize_t awrite(int fd,void *buf, size_t count);
ssize_t aread(int fd, void *buf, size_t count);
int aopen(const char *pathname, int flags, int  mode_t mode);
int aclose(int fd);
off_t alseek(int fd, off_t offset, int whence);
int main()
{
	char buff[100];
	int fd1,fd2,rval,len=10,r;
	fd1=aopen("a.txt",0,O_RDONLY);
	if(fd1<0)
	{
		//		Perrno("open fail because");
		printf("\n%d",errno);
		exit(1);
	}
	fd2=aopen("r.txt",O_CREAT|O_RDWR,0777);
	rval=aread(fd1,buff,len);
	buff[rval]='\0';
	printf("%s\n",buff);
	awrite(fd2,buff,rval);
	r=alseek(fd1,-10,2);
	rval=aread(fd1,buff,r);
	awrite(fd2,buff,rval);
	printf("%s\n",buff);
	aclose(fd1);
	aclose(fd2);
	return 0;
}
