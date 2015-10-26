#include "stdio.h"
#include "fcntl.h"
#include "fop.h"
main()
{
	int fd,r,l=13;
	char buff[230];
	fd=aopen("venky.txt",0,O_RDONLY);
	r=aread(fd,buff,l);
	buff[r]='\0';
	printf("%s\n",buff);
	alseek(fd,-15l,2);
	r=aread(fd,buff,10);
	buff[r]='\0';
	printf("%s\n",buff);
	aclose(fd);
}
