#include<stdio.h>
#include<fcntl.h>

main()
{
  	int fd, retval;
	char buff[100];

	if((fd = open("testpipe", O_RDONLY))<0)
		perror("pipe open failed");

	retval = read(fd, buff, 10);

	if (retval < 0)
		perror("read failed");

	buff[retval] = '\0';

	printf("message recived : %s\n", buff);

}
