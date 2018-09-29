#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 1024

int main()
{
    int fd;
	char buff[MAX];
    fd = open("myfifo", O_RDWR);
    write(fd, "Hi", sizeof("Hi"));
	read(fd,buff,MAX);
	printf("named1-->side received : %s\n", buff);
    close(fd);
}
