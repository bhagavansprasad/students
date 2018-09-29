#include <stdio.h>
#include <fcntl.h>
main()
{
	int a=5;
	close(1);
	printf("---%d\n",a);
	int fd=open("t.txt",O_RDONLY);
	printf("----fd:%d\n",fd);
	int fd1=open("o.txt",O_RDWR);
	printf("----fd:%d\n",fd1);
	//close(fd1);
	//close(1);
	dup(fd1);
}
