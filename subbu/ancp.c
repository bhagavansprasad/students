#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
main()
{
	int length=10;
	char buff[300];
	int rtval=0,fd;
	fd=open("g.txt",O_RDONLY);
	rtval=read(fd,buff,length);
	buff[rtval]='\0';
	printf("%s\n",buff);
	lseek(fd,-11L,2);
		rtval=read(fd,buff,length);
	buff[rtval]='\0';
	printf("%s\n",buff);
}
