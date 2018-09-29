#include <stdio.h>
#include <fcntl.h>
main()
{
	while(1)
	{
	int fd=open("t.txt",O_RDONLY);	
	printf("---fd:%d\n",fd);
	if(fd<0)
		break;
	}
	sleep(100);
}
