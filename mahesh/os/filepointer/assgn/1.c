#include <stdio.h>
#include <fcntl.h>
main()
{
	
	int fd1=open("t.txt",O_RDONLY);
	printf("---fd1:%d\n",fd1);
	int fd2=open("t.txt",O_RDONLY);
	printf("---fd2:%d\n",fd2);
	int fd3=open("t.txt",O_RDONLY);
	printf("---fd3:%d\n",fd3);
	int fd4=open("o.txt",O_RDONLY);
	printf("---fd4:%d\n",fd4);
	int fd5=open("t.txt",O_RDONLY);
	printf("---fd5:%d\n",fd5);
	int fd6=open("t.txt",O_RDONLY);
	printf("---fd6:%d\n",fd6);
	int a=5;
	close(1);
	printf("----%d\n",a);
	close(fd4);
	dup(fd4);
   //int  fd7=open("o.txt",O_RDONLY);
   //printf("----fd7:%d\n",fd7);
}
