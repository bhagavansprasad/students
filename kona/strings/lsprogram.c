#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd1,r,l=20;
	char buf[100];
	fd1=open("strings",O_RDONLY);
	r=read(fd1,buf,l);
	buf[r]='\0';
	printf("the value of buf is %s\n",buf);
	close(fd1);
}
