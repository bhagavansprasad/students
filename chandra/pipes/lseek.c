#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,rd;
	char msg[11];
	fd = open("balu", O_RDONLY);
	lseek(fd, 2l, 0);
	rd = read(fd, msg, 11);
	printf("rd val is : %d\n", rd);
	printf("msg  is : %s\n", msg);

}
