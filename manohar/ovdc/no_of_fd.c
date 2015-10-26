#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
main()
{
	int i=1,fd;
	for(i=1;i<=65535;i++)
	{
		fd= open("1.txt",O_RDONLY);
		if(fd == -1)
		{
		perror("file can not opened\n");
		exit(0);
		}
		printf("fd[%d]---->%d\n",i,fd);
	}
}
