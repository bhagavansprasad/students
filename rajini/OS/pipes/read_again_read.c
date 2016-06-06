#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,rval;
	char buff[20];
	char *m="bangalore";
	fd = open("type",O_RDWR);
	pid = fork();
	if(pid > 0)
	{
		write(fd,m,sizeof("bangalore"));
	}
	else
	{
		sleep(2);
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("--->first time:%s\n",buff);
		rval = read(fd,buff,20);
		buff[rval]='\0';
		printf("--->second time:%s\n",buff);
	}
}
