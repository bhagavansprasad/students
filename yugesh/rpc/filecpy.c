#include <stdio.h>
#include <fcntl.h>
#include"fop.h"
main()
{
	char buff[500];
	int fd1,fd2,rv,vr,len=10;
	fd1=aopen("a.txt",O_RDONLY,0644);
	fd2=aopen("e.txt",O_CREAT|O_RDWR,0644);
	while(1)
	{
		rv=aread(fd1,buff,len);
		buff[rv]='\0';
		if(rv!=0)
		vr=awrite(fd2,buff,rv);
		else
		break;
	}
	aclose(fd1);
	aclose(fd2);
}
