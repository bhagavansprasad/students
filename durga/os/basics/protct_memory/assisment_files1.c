#include<stdio.h>
#include <fcntl.h>
int r;
int len = 10;
int fd;
main()
{
char buf[20];
	int pid ,i;
	fd = open("t.txt", O_RDONLY);
	pid = fork();
	if(pid == 0)
	{
	  printf("----->>child is under working------->>>\n");
		printf("the fd valuue in child is %d\n", fd);
		for(i = 0; i<2; i++)
		{
		printf("the position of the file pointer in child %d\n", r);
		sleep(2);
		r = read(fd , buf, len);
		}
	}
	else
	{
	  printf("----->>psrent is under working------->>>\n");
		printf("the fd valuue in parent is %d\n", fd);
		for( i = 0; i<2; i++)
		{
		r = read(fd , buf, len);
		sleep(2);
		printf("the position of the file pointer in parent %d\n", r);
		}
	}

}
