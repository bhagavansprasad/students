#include <fcntl.h>
#include <stdio.h>
#define SIZE 63

main()
{
	int fd;
	char msgbuff[SIZE+1];
	if(mknod("myfifo",010666,0)<0)
		perror("my fifo failed");

	if(fd = open("myfifo",O_RDWR))
}
