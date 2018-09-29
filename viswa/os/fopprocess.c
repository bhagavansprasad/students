#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd, pid , len = 10, rfd = 0, wfd = 0;
	char buff[100];

	fd = open("t.txt" , O_RDONLY,0);
	pid = fork();
	
	if(pid == 0)
	{
		rfd = read(fd ,buff , len);
		buff[rfd] = '\0';
		printf("chilld buff ::::%s\n", buff);
		printf("fd: %d\n",fd);

	}
	else
	{
		wfd = read(fd , buff ,len);
		buff[wfd] = '\0';
		printf("parent buff :::%s\n", buff);
		printf("fd: %d\n",fd);
	}

}
