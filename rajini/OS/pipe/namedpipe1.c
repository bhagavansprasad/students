#include <stdio.h>
#include <fcntl.h>
#define SIZE 20
main()
{
	int fd,rval;
	char msg[SIZE]="hi";
	fd = open("myfifo",O_RDWR);
	if(fd < 0)
		printf("pipe open failed\n");
	rval = write(fd,msg,SIZE+1);
	printf("write rval is : %d\n",rval);
}

