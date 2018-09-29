#include <stdio.h>
#include <fcntl.h>
main()
{
	int pid,fd,rval,len;
	char buff[100];
	pid=fork();
	fd=open("a.txt",O_RDONLY);
	if(pid==0)
	{
		printf("child process");
		printf("%d\n",fd);
		rval=read(fd,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
	}
	if(pid>0)
	{
		printf("parent process");
		printf("%d\n",fd);
		rval=read(fd,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
	}
}

