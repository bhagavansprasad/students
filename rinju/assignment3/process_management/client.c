#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
main()
{
	char buff1[50] = "hi how are you";
	int fd1,fd2 ,retval,ret;
	char *fifo1 = "fifo1";
	char *fifo2 = "fifo2";
	mkfifo (fifo1,0666);
	mkfifo (fifo2,0666);
	//	printf("input to server\n");
	//	scanf("%s",buff);
	fd1 = open(fifo1,O_WRONLY);
	fd2 = open(fifo2,O_RDONLY);
	retval = write(fd1,buff1,sizeof(buff1));
	if(retval)
		printf("write complete\n");
	ret = read(fd2, buff1, sizeof(buff1));
	if(ret)
		printf("read complete\n");
	printf("Received: %s\n", buff1);


	close(fd1);
	close(fd2);

	return 0;
}


