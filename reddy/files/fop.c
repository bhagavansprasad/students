#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,r,len=30;
	char buff[100];
	fd=aopen("reddy.txt",0,O_RDONLY);
	while(1)
	{
		r=read(fd,buff,len);
		buff[r]='\0';
		printf("%s",buff);
		if(r<len)
			break;
	}
	aclose(fd);
}
