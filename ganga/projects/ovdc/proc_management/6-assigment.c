#include <stdio.h>
#include <fcntl.h>

main()
{
	int fd = -1, i = 0, retval = 0, len = 2048, giffs_count;
	char buff[4*1024];
	char temp[100] = "" ;

	sprintf(temp, "/proc/%d/stat", 2187);

	fd = open(temp, O_RDONLY);
	if(fd < 0)
	{
		printf( "open failure\n");
		return -1;
	}

	retval = read(fd, buff, len);
	retval[buff] = '\0';
	close(fd);

	printf("%s", buff);

}
