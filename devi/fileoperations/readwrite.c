#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
int main()
{
	char buff[10];
	int fd1,fd2,rval,wval,len=10;
	fd1=open("a.txt",0,O_RDONLY);
	if(fd1<0)
	{
	perror("file not opened because");
	exit(1);
	}
	fd2=open("p.txt",0777,O_CREAT|O_RDWR);
	if(fd2<0)
	{
	perror("file cant be write");
	close(fd1);
	exit(1);
	}
	while(1)
	{
		rval=read(fd1,buff,len);
		buff[rval]='\0';
     	printf("%s",buff);
		wval=write(fd2,buff,rval);
		printf("%d",wval);
		printf("\n %s",buff);
		if(rval<len)
			break;
	}
	close(fd1);
	close(fd2);
	return 0;
}
