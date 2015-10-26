#include"stdio.h"
#include "fcntl.h"
#include "fop.h"

main()
{
	char buff[100];
	int fd,fd1,r,w,len=10;
	
	fd=aopen("txt.c",O_RDONLY,0);
	fd1=aopen("t.c",O_RDWR|O_CREAT,0777);
	
	r=aread(fd,buff,len);
	buff[r]='\0';
	
	w=awrite(fd1,buff,r);
	alseek(fd,-10l,2);
	
	r=aread(fd,buff,len);
	buff[r]='\0';
	
	w=awrite(fd1,buff,r);
	
	aclose(fd1);
	aclose(fd);
}

