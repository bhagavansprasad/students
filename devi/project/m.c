#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
       ssize_t aread(int fd, void *buf, size_t count);
       off_t alseek(int fd, off_t offset, int whence);
       ssize_t awrite(int fd,void *buf, size_t count);
       int aclose(int fd);
       int aopen(const char *pathname, int flags, mode_t mode);
int main()
{
	int fd1,fd2,rval,len=10,r;
	char buff[100];
	fd1=aopen("a.txt",0,O_RDONLY);
	if(fd1<0)
	{
		perror("file cant be open bcoz");
		exit(1);
	}
	fd2=aopen("r.txt",O_CREAT|O_RDWR,0777);
	if(fd2<0)
	{
		perror("file cant be write");
		aclose(fd1);
		exit(1);
	}
		rval=aread(fd1,buff,len);
		buff[rval]='\0';
		printf("buff=%s rval=%d\n",buff,rval);
		awrite(fd2,buff,rval);
		printf("buff=%s rval=%d\n",buff,rval);
		r=alseek(fd1,-10,2);
		rval=aread(fd1,buff,r);
		printf("\nbuff=%s r=%d\n",buff,r);
		awrite(fd2,buff,rval);
		printf("buff=%s rval=%d\n",buff,rval);
		aclose(fd1);
		aclose(fd2);
		return 0;
}
