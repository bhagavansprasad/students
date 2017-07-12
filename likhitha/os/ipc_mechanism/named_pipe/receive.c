#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

main()
{
	char buff[50];
	int fd1,fd2 ,retval;

	char *fifo1 = "fifo1";
	char *fifo2 = "fifo2";

	mkfifo (fifo1,0666);
	mkfifo (fifo2,0666);
	//	fd1 = open(fifo1,O_RDONLY);
	//	fd2 = open(fifo2,O_WRONLY);

	while (1)
	{
		fd1 = open(fifo1,O_RDONLY);
		fd2 = open(fifo2,O_WRONLY);

		retval = read(fd1, buff, 50);
		buff[retval] = '\0';

		if (strcmp("",buff)!=0)
		{
			printf("Received: %s\n", buff);
			printf("Sending back...\n");
			write(fd2,buff,50);
		}

		/* clean buf from any data */
		memset(buff, 0, sizeof(buff));
	}

	close(fd1);
	close(fd2);

	unlink(fifo1);
	unlink(fifo2);

	return 0;
}

