#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int fd=0,t=0,i;
	char buff[400];

	fd=open("t.txt",0,O_RDONLY);
	for(i = 0; i <= t; i++)
	{
		t=read(fd,buff,10);
		buff[t]='\0';
		printf("%s\n", buff);
		printf("%d\n", t);
	}
	close(fd);
}
