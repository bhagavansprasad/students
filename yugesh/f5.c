#include <stdio.h>
main()
{
	int len=10;
	char buff[300];
	int retval=0,fd=0;
	fd=open("t.txt",O_RDONLY);
	retval=read(fd,buff,len);
	buff[retval]='\0';
	printf("%s",buff);
	lseek(fd,-11l,2);
	retval=reada(fd,buff,len);
	buff[retval]='\0';
	printf("%s",buff);
}
