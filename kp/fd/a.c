#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd, offset;

	fd = open("a.txt", O_RDONLY);

	printf("-->After opening file\n");
	offset = lseek(fd, 0, SEEK_CUR);
	printf("-->offset :%d\n", offset);

	printf("-->forward 20 bytes\n");
	offset = lseek(fd, 20, SEEK_CUR);
	printf("-->offset :%d\n", offset);

	printf("-->going to end of the file\n");
	offset = lseek(fd, 0, SEEK_END);
	printf("-->offset :%d\n", offset);

	printf("-->going back 20 bytes from end of the file\n");
	offset = lseek(fd, -20, SEEK_END);
	printf("-->offset :%d\n", offset);
}

