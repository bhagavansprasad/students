#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
main()
{
	char buff[10];
	int fd1,fd2,rval,wval,len=10,r;
	fd1=aopen("a.txt",O_RDONLY);
//	printf("%d",fd1);
	if(fd1<0)
	{
		printf("\n%d",errno);
		exit(1);
	}
	fd2=aopen("r.txt",O_CREAT|O_RDWR);
	rval=aread(fd1,buff,len);
	buff[rval]='\0';
	printf("%s",buff);
	wval=awrite(fd2,buff,rval);
	r=alseek(fd1,-10,2);
	rval=aread(fd1,buff,r);
	awrite(fd2,buff,rval);
	aclose(fd1);
	aclose(fd2);
	}
