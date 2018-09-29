#include <fcntl.h>
#include <stdio.h>

main()
{
	int fd,rd;
	char msg[11];
	fd = open("xxx", O_RDONLY);
	lseek(fd , 21, 0);
	rd = read(fd , msg , 11);
	printf("read rd:%d\n",rd);
	printf("msg:->%s\n",msg);
}
