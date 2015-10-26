#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,rval,len=10,pid;
	char buff[100];
	pid=fork();
	if(pid==0)
	{
        printf("child process");
		fd=open("c.txt",O_RDONLY);
		printf("%d\n",fd);
		rval=read(fd,len,buff);
		buff[rval]='\0';
		printf("%s\n",buff);
		close(fd);
	}
	if(pid>0)
	{
	    printf("parent process");
		fd=open("c.txt",O_RDONLY);
		printf("%d\n",fd);
		while(1)
		{
		rval=read(fd,len,buff);
		buff[rval]='\0';
		printf("%s\n",buff);
		}
	}
}
