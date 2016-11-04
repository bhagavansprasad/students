#include <stdio.h>
#include <fcntl.h>
#define SIZE 20
main()
{
	int fd,rval = 0;
	char buff[SIZE];
	fd = open("myfifo",O_RDWR);
	if(fd<0)
		printf("pipe failed\n");
	rval = read(fd,buff,SIZE+1);
	buff[rval]='\0';
	printf("s:%s\n",buff);
}
