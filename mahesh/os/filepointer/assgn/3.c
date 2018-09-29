#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd1=open("t.txt",O_RDONLY);
	printf("---fd:%d\n",fd1);
	int fd2=open("a.txt",O_RDONLY);
	printf("---fd:%d\n",fd2);
	int fd3=open("b.txt",O_RDONLY);
	printf("---fd:%d\n",fd3);
}
