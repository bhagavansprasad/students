#include <stdio.h>
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,fd1,r,l=12,w;
	char buff[200];
	fd=aopen("venky.txt",O_RDONLY,0);
	fd1=aopen("b.txt",O_CREAT|O_RDWR,0777);
	r=aread(fd,buff,l);
	buff[r]='\0';
	w=awrite(fd1,buff,r);
	aclose(fd);
	aclose(fd1);
}
