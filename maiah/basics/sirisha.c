#include <stdio.h>
#include<fcntl.h>
main()
{
	int fd,r,i,l=10;
	char buff[100];
	fd=open("venky.txt",0,O_RDONLY);
	while(1)
	{
	r=read(fd,buff,l);
	buff[r]='\0';
	printf("%s",buff);
	}
	close(fd);
}

