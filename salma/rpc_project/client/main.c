#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include"fop.h"
main()
{
	client_req();
	int fd1,fd,r,w,l=10;
	char buf[100];
	fd=aopen("sample.txt",O_RDONLY,0);
	printf("fd value is %d\n",fd);
	fd1=aopen("sample4.txt",O_CREAT|O_RDWR,0644);
	printf("fd1 value is%d\n",fd1);
	while(1)
	{
		r=aread(fd,buf,l);
		buf[r]='\0';
		w=awrite(fd1,buf,r);
		if(r<l)
			break;
	}
	aclose(fd);
	aclose(fd1);
}
