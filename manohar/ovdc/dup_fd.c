#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
	int i;
	int fd;
	close(0);
	close(2);
	for(i=1;i<=13;i++)
	{
		fd = open("2.txt",O_RDONLY);
		if(i==5)
		dup(5);
		else if (i==7)
		dup(7);

		printf("fd[%d]----->%d\n",i,fd);
	}
}
