#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
main()
{
	int fd, rfd, len = 10, i;
	char buff[100];
	fd = open("proc/1533/stat", O_RDONLY);
	printf("fd  value is : %d\n", fd);
	for(i = 0; i < 5; i++)
	{
		while(1)
		{
			rfd = read(fd, buff, len);
			buff[rfd] = '\0';
			//printf("rfd  value is : %d\n", rfd);
			printf("buff  value is : %s\n", buff);
			if(rfd < len)
				break;
		}
		sleep(1);
		lseek(fd, 0l, 0);
	}

}
