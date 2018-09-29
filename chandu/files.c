#include<stdio.h>
#include <fcntl.h>
#include<string.h>
main()
{
	char buffer[100];
		int retval=0,l=10;
	int fd;
	fd = open("my.txt",O_RDONLY);
	while(1)
	{
		retval = read(fd,buffer,10);
		buffer[retval]='\0';
			printf("%s",buffer);
		if(retval<10)
		{
			//printf("%s",buffer,l);
			break;
		}
	}
	close(fd);
}
