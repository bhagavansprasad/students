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
	int i;
	fd1=open("a.txt",O_RDONLY);
	if(fd1<0)
	{
//		Perrno("open fail because");
		printf("\n%d",errno);
		exit(1);
	}
	fd2=open("r.txt",O_CREAT|O_RDWR);
	rval=read(fd1,buff,len);
	buff[rval]='\0';
	printf("%s",buff);
	for(i=0;buff[i]!='\0';i++)
	{
	if(buff[i]>=97 && buff[i]<=122)
	buff[i]=buff[i]-32;
	else if(buff[i]>=65 && buff[i]<=90)
	buff[i]=buff[i]+32;
	else
	buff[i]=buff[i];
	}
	wval=write(fd2,buff,rval);
	r=lseek(fd1,-10,2);
	rval=read(fd1,buff,r);
	for(i=0;buff[i]!='\0';i++)
	{
	if(buff[i]>=97 && buff[i]<=122)
	buff[i]=buff[i]-32;
	else if(buff[i]>=65 && buff[i]<=90)
	buff[i]=buff[i]+32;
	else
	buff[i]=buff[i];
	}
	write(fd2,buff,rval);
	close(fd1);
	close(fd2);
	}
