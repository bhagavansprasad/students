#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main()
{
	char buff[200];
	int fd=open("a.txt",O_RDONLY);
	int retval=read(fd,buff,100);
	printf("%d",retval);
	buff[retval]='\0';
	printf("%s",buff);
	close(fd);
}
