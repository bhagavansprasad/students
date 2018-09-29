#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"pen.h"
int main()
{
	int r,w,l,fd=0,fd1=0;
	char buff[100];
	fd=aopen("y.txt",0,O_RDONLY);
	fd1=aopen("d.txt",O_CREAT|O_WRONLY,0777);
	while(1)
	{
		r=aread(fd,buff,10);
		buff[r]='\0';
		w=awrite(fd1,buff,r);
		if(r<10)
			break;
	}
	l=alseek(fd,0,SEEK_SET);
	r=aread(fd,buff,10);
	buff[r]='\0';
	w=awrite(fd1,buff,r);

	l=alseek(fd,-10,SEEK_END);
	r=aread(fd,buff,10);
	buff[r]='\0';
	w=awrite(fd1,buff,r);

	aclose(fd);
	aclose(fd1);
}
