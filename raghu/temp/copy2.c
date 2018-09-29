#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	char buff[100];
	int fd1,fd2,s=0,i;
	fd1=aopen("t1.txt",O_RDONLY);
	fd2=aopen("t.txt",O_WRONLY);
	while(1)
	{
		s=aread(fd1,buff,10);
		awrite(fd2,buff,10);
		buff[s]='\0';
		printf("%s",buff);
		if(s<10)
		break;
	}

}

int aopen(char *fd1,int O_RDONLY)
{
	int fd1=open(fd1,O_RDONLY);
	return fd;
}

int aread(int fd,char *buff,int len)
{
	int 
}
