#include <stdio.h>
#include <fcntl.h>
main()
{
	int r,fd;
	char buff[100];
	fd=open("venky.txt",0,O_RDONLY);
	r=read(fd,buff,20);
	buff[r]='\0';
	printf("%s\n",buff);
	lseek(fd,-30l,2);
	r=read(fd,buff,10);
	buff[r]='\0';
	printf("%s\n",buff);
}

