#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 1024

int main()
{
    int fd,fd1;
	char buff[MAX];
	char buf[]="hi";
    fd = open("testfile", O_RDWR);
    write(fd, buf, sizeof (buf));
	read(fd,buff,MAX);
	printf("named1-->side received : %s\n", buff);
    close(fd);
}
