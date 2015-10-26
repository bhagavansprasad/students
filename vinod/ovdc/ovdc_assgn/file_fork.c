#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void parent();
void child();
int fd=0, off=0;
int main()
{
	int p=0;
	fd = open("x.txt", O_RDONLY);
	p=fork();
	if(0==p)
		child();
	else
		parent();
	return 0;
}

void child()
{
	for(;;)
	{
		off = lseek(fd, 0, 1);
		printf("-->C: offset :%d\n", off);
		printf("-->C: pid :%d, ppid :%d\n", getpid(), getppid());
		sleep(1);
	}
}

void parent()
{
	for(;;)
	{
		off = lseek(fd, 50, 1);
		printf("-->P: offset :%d\n", off);
		printf("-->P: pid :%d, ppid :%d\n", getpid(), getppid());
		sleep(1);
	}
}
