#include<stdio.h>
#include <fcntl.h>
int main()
{
	int fd,fd1,pid;
	char buff[100];
	fd=open("namedpipe1",O_RDWR);
	fd1=open("namedpipe2",O_RDWR);
	pid=fork();
	if(pid==0)
	{
		write(fd,"hai",10);
		read(fd1,buff,10);
		printf("child :%s\n",buff);
		write(fd,"bye",10);
		read(fd1,buff,10);
		printf("child :%s\n",buff);
	}
	else
	{
		read(fd,buff,10);
		printf("parent :%s\n",buff);
		write(fd1,"hello",10);
		read(fd,buff,10);
		printf("parent :%s\n",buff);
		write(fd1,"bye",10);
	}
}	
