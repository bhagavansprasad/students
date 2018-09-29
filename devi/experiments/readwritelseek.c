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
	fd1=open("a.txt",O_RDONLY);
	//	printf("%d",fd1);
	if(fd1<0)
	{
		perror("file cant be open bcoz");
		printf("\n%d",errno);
		exit(1);
	}
	fd2=open("r.txt",O_CREAT|O_RDWR);
	buff[rval]='\0';
	rval=read(fd1,buff,len);
	printf("%s",buff);
	wval=write(fd2,buff,rval);
	r=lseek(fd1,-10,2);
	rval=read(fd1,buff,r);
	write(fd2,buff,rval);
	close(fd1);
	close(fd2);
}
