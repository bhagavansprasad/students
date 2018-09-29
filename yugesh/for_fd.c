#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,rval,len=10;
	char buff[100];
	fd = open("a.txt",O_RDONLY);
	pid = fork();
	if(pid==0)
	{
	printf("%d\n",fd);
	rval=read(fd,buff,len);
	buff[rval]='\0';
	printf("%s\n",buff);
	}
	else if(pid>0)
	{
	printf("%d\n",fd);
	rval=read(fd,buff,len);
	buff[rval]='\0';
	printf("%s\n",buff);
	}
	close(fd);

}
