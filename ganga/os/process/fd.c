#include <stdio.h>
#include <fcntl.h>

main()
{
	static int fd;
	int i;
	for(i = 0; i <= 1020 ;i++)
	{
		fd = open("a.txt", O_RDWR | O_CREAT, 0744);
		printf("--> fd value is: %d\n", fd);
	}
} 
