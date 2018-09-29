#include <stdio.h>
#include<fcntl.h>
#include<errno.h>
#include"afop.h"
#include "rpcc.h"
main()
{
	int fd,fd1,l=10,r,w;
	char buf[100];
	fd=aopen("first.txt",O_RDONLY,0);
	fd1=aopen("new.txt",O_RDWR|O_CREAT,0777);
		r=aread(fd,buf,l);
		buf[r]='\0';
		w=awrite(fd1,buf,r);
		if(w<0)
		{
			printf("not written:");
			printf("%d",errno);
		}
	aclose(fd);
}
