#include <fcntl.h>
main()
{
	int fd;
	fd=open("t.c",O_RDONLY);
	lseek(fd,01,5);
}
