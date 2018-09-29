#include <stdio.h>
int len=10;
char buff[312];
main()
{
	fd1=open("a.txt",O_RDONLY);
	fd2=open("b.txt",CREAT);
	retval=read(fd1,buff,len);
	if(retval>0);
	write(fd2,buff,len);
	else
		break;
	close(fd1);
		close(fd2);
}
