#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024
int main()
{
	int fd;
	int pid;
	char buf[MAX_BUF];
	char buff[]="hello";
	char buf1[]="hi";
	fd = open("testfile", O_RDWR);
	pid=fork();
	if(pid==0)
	{
		write(fd, buf1, sizeof (buf1));
		sleep(5);
		read(fd, buf, MAX_BUF);
		printf("child is received: %s\n", buff);
	}
	else
	{
		read(fd, buf, MAX_BUF);
		printf("parent is  Received: %s\n", buf1);
		write(fd, buff, sizeof (buff));
		sleep(5);
		close(fd);

		return 0;
	}
}	
