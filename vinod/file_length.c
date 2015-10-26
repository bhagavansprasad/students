#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "errno.h"

int main()
{
	char buff[100];
	int retval=0,sum=0;
	int fd = open("g.txt",O_RDONLY);
	
	if(fd < 0)
	{
		perror("open return failure because..");
		printf("-->errno :%d\n", errno);
		exit(1);
	}

	do
	{
		retval = read(fd,buff,10);
		sum += retval;
		buff[retval] = '\0';
	}while(retval > 1);

	printf("Length of file:%d Bytes\n",sum);
	return 0;
}
