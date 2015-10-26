#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 5
int main()
{
	int fd;
	int pid;
	char buf[MAX_BUF];
	char buff[]="auranetworks";
	char buf1[]="bangalore";
	fd = open("testfile", O_RDWR);
	pid=fork();
	if(pid==0)
	{
		write(fd, buf1, MAX_BUF);
		sleep(3);
		read(fd, buff, MAX_BUF);
		printf("child is received: %s\n", buf);
	}
	else
	{
		read(fd, buf, MAX_BUF);
		printf("parent is  Received: %s\n", buf);
		write(fd, buff, MAX_BUF);
		sleep(3);
		close(fd);

		return 0;
	}
}	
