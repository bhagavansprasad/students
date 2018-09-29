#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd=0,fd1=0,w,r,len=10;
	char buff[100];
	fd=open("a.txt",0,O_RDONLY);
	fd1=open("x.txt",O_CREAT|O_WRONLY,0777);
	while(1)
	{
		r=read(fd,buff,len);
		buff[r]='\0';
		w=write(fd1,buff,r);
		if(r<len)
		break;
	}
	close(fd);
	close(fd1);
}
