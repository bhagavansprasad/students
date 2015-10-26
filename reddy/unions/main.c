#include <stdio.h>
#include <fcntl.h>
#include "fop.h"
main()
{
	int fd,fd1,r,w,ls,cl,l=10;
	char buff[100];

	fd=aopen("reddy.txt",O_RDONLY,0);
	printf("------>fd value is : %d\n",fd);

	fd1=aopen("b.txt",O_CREAT|O_RDWR,0777);
	printf("--->fd1 value is :%d\n",fd1);

	r=aread(fd,buff,l);
	buff[r]='\0';

	printf("%s\n",buff);

	w=awrite(fd1,buff,r);

	ls=lseek(fd,-20l,2);
	r=aread(fd,buff,20);
	buff[r]='\0';

	printf("%s\n",buff);

	w=awrite(fd1,buff,r);

	aclose(fd1);
	aclose(fd);
}
