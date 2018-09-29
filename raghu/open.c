#include <stdio.h>
#include <fcntl.h>
main()
{
	int i,fd;
	for(i=1;i < 1024;i++)
	{
		fd = open("t.txt",O_RDONLY,0);
		printf("%d",fd);
	}
}
