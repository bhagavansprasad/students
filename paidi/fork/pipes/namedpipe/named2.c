#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char buf[MAX_BUF];

    fd = open("myfifo", O_RDWR);
    read(fd, buf, MAX_BUF);
    printf("named2-->side Received: %s\n", buf);
	write(fd, "paidi", sizeof("paidi"));
    close(fd);

    return 0;
}
