#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,fd1,r,w,l=10;
	char buff[830];
	fd=aopen("venky.txt",O_RDONLY,0);
	fd1=aopen("b.txt",O_CREAT|O_RDWR,0777);
	r=aread(fd,buff,l);
	buff[r]='\0';
	w=awrite(fd1,buff,r);
	alseek(fd,-20l,2);
	r=aread(fd,buff,l);
	buff[r]='\0';
	w=awrite(fd1,buff,r);
	aclose(fd1);
	aclose(fd);
}
