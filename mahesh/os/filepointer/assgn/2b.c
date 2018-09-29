#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd=open("t.txt",O_RDONLY);
	printf("---fd:%d\n",fd);
	int fd2=open("t.txt",O_RDONLY);
	printf("---fd2:%d\n",fd2);
}
