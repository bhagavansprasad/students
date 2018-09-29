#include <stdio.h>
#include <fcntl.h>
int d;
main()
{
	int fd1,fd2,r;
	int l=10;
	char buff[100];
	int pid=fork();
	if(pid>0)
	{
		fd1=open("t.txt",O_RDONLY,0);
		d = lseek(fd1, 0, 1);
		printf("---->Parent is fppos :%d\n",d);
		sleep(5);
		d = lseek(fd1, 0, 1);
		printf("---->Parent is fppos :%d\n",d);
		sleep(2);
	}
	else
	{
		fd1=open("t.txt",O_RDONLY,0);
		d = lseek(fd1, 0, 1);
		printf("---->Child is fppos :%d\n",d);
		printf("---->Child moving fp for 10 bytes\n");
		d = lseek(fd1, 10l, 1);
		printf("---->Child is fppos :%d\n",d);
		sleep(8);
	}
	close(fd1);
}
