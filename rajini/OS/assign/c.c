#include <stdio.h>
#include <fcntl.h>
main()
{
	int pid=0;
	char buff[100];
	pid=fork();
	if(pid==0)
	{
		int fd,r,len=6;
	    char buff[100];
		fd=open("t.txt",O_RDONLY,0777);
		while(1)
		{
			r=read(fd,buff,len);
			buff[r]='\0';
			printf(" r ::%d\n buff ::%s\n",r,buff);
			sleep(2);
			if(r<len)
				break;
		}
		close(fd);
	}
	else
	{
		int fd1,r,len=5;
	    char buff[100];
		fd1=open("t.txt",O_RDONLY,0777);
		while(1)
		{
			r=read(fd1,buff,len);
			buff[r]='\0';
			printf(" r ::%d\n buff ::%s\n",r,buff);
			sleep(2);
			if(r<len)
				break;
		}
		close(fd1);
	}
}

