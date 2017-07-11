#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
main()
{
	char buff1[50] = "hi how are you";
	int fd1,fd2;
	char *fifo1 = "temp/fifo1";
	char *fifo2 = "temp/fifo2";
	mkfifo (fifo1,0666);
	mkfifo (fifo2,0666);
//	printf("input to server\n");
//	scanf("%s",buff);
	fd1 = open(fifo1,O_WRONLY);
	fd2 = open(fifo2,O_RDONLY);
	write(fd1,buff1,sizeof(buff1));
		read(fd2, buff1, sizeof(buff1));

			printf("Received: %s\n", buff1);


	close(fd1);
	close(fd2);

	return 0;
}


