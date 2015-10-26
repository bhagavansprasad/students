#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int fd,i,j=10;
	char buff[100];
	fd=open("tetx.txt",O_RDONLY);
	while(1)
	{
		i=read(fd,buff,j);
		buff[i]='\0';
		if(i<j)
		{
			printf("%s",buff);
			break;
		}
		printf("%s",buff);
	}
}
