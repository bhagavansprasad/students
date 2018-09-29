#include<stdio.h>
#include "fcntl.h"
main()
{
	int length =32;
	char buff[512];
	int fd =open("a.txt",O_RDONLY);
	int returnvalue=read(fd,buff,length);
	if(returnvalue>0)
	{
		printf("%s",buff);
	}
	close(fd);
}
