#include <fcntl.h>

main()
{
	int fd;
	
	fd = open("t.txt",O_RDONLY);
	lseek(fd , 01 , 5);
}
