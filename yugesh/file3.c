#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,len=10,rval;
	char buff[100];
		fd=open("c.txt",O_RDONLY);
		printf("%d\n",fd);
		while(1)
		{
		rval=read(fd,len,buff);
		buff[rval]='\0';
        printf("%s\n",buff);
		}
}
