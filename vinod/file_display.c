#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
main()
{
	char buff[100];
	int retval=0;
	int fd = open("g.txt",O_RDONLY);
	if(fd==-1)
	{
		printf("file not exist \n");
	}
	else
	{
		do
		{
			retval = read(fd,buff,5);
			buff[retval]='\0';
			if(retval>1)
				printf("%s",buff);
		}while(retval>1);
		printf("\n");
	}
}
