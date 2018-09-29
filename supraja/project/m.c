#include <stdio.h>
#include <fcntl.h>
int main()
{
	char buff[200];
	int fd,fd1,rval;

	fd  = open("t.txt",O_RDONLY);
	fd1 = open("t3.txt",O_WRONLY);
	while(1)
	{
		rval=read(fd,buff,10);
		buff[rval]='\0';
		write(fd1,buff,rval);
		if(rval<10)
		  break;
	}

	close(fd);
	close(fd1);
}
