#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,r,t,l=8;
	char buff[200];
	fd=aopen("venky.txt",0,O_RDONLY);
	while(1)
	{
		r=aread(fd,buff,l);
		buff[r]='\0';
		printf("%s",buff);
		if(r<l)
			break;
	}
	t=aclose(fd);
}
