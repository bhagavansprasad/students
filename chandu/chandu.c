#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

main()
{
	int length=10, retval;
	char buffer[1000];
	int fd = -1;

	fd = open("chandu.txt", O_RDONLY);
	retval = read(fd, buffer, 500);

	printf("%s\n", buffer);						

	close(fd);
}
