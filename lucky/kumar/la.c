#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>
#include "ks.h"
int main()
{
	int r,fd=0,fd1=0;
	char buf[100];
	fd=aopen("l.txt",O_RDONLY,0);
	fd1=aopen("o.txt",O_CREAT|O_WRONLY,0777);
	r=aread(fd,buf,10);
	buf[r]='\0';
	awrite(fd1,buf,r);
	alseek(fd,0,SEEK_SET);
	r=aread(fd,buf,10);
	buf[r]='\0';
	awrite(fd1,buf,r);
	alseek(fd,-10,SEEK_END);
	r=aread(fd,buf,10);
	buf[r]='\0';
	awrite(fd1,buf,r);
	aclose(fd);
	aclose(fd1);
return 0;
}
