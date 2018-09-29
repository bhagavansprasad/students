#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd, rfd, wfd, len = 10;
	char buff[80];
	fd = open("/dev/chardev", O_RDWR, 0777);
	printf("open fd is : %d\n", fd);

	rfd = read(fd, buff, len);
	buff[rfd] = '\0';
	printf("read buff is : %s\n", buff);

	wfd = write(fd, buff, rfd);
	printf("write buff is : %s\n", buff);

	close(fd);
}
