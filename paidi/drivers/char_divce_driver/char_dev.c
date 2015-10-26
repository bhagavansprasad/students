#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	int fd,fd1;
	char bu[500];
	fd = open("/dev/chardev", O_RDONLY);
	fd1 = open("dev.txt",O_WRONLY);
	read(fd,bu,500);
	write(fd1,bu,500);
	printf("the buffer is :%s\n",bu);
}
