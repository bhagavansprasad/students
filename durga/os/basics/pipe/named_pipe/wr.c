#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

main()
{
	int fd, nwrite;

	if((fd = open("testpipe", O_WRONLY))<0)
	{
		printf("print the fd : %d\n", fd);
		perror("file open failed");
	}
	c

	if((nwrite = write(fd, "I am prasad, bangalore", 10))<=0)
		perror("message write faiel");
}

