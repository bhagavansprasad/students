#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd,fd1;
    char buf[MAX_BUF];
    char buff[]="hello";
    fd = open("testfile", O_RDWR);
    read(fd, buf, MAX_BUF);
    printf("named2-->side Received: %s\n", buf);
	write(fd, buff, sizeof (buff));
    close(fd);

    return 0;
}
