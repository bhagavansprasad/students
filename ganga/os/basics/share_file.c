#include <stdio.h>
#include <fcntl.h>

main()
{
	int pid = fork();
	int fd1, fd2, wretval, retval;
	char buffer[256]  = " hi hello this is Aura Networks";

	if(pid)
	{
		printf("---> In Parent\n");
		fd1= open("t.txt", O_CREAT | O_RDWR);
		printf(" fd value : %d\n", fd1);
		wretval = write(fd1, buffer, 10);
		buffer[wretval] = '\0';
		printf("--> value of wretal : %d\n", wretval);
		printf("--> writing into the buffer : %s\n", buffer);
		close(fd1);
	}
	else
	{
		printf("---> In Child\n");
		fd1= open("t.txt", O_CREAT | O_RDWR);
		printf(" fd value : %d\n", fd1);
		retval = read(fd1, buffer, 10);
		buffer[wretval] = '\0';
		printf("--> the value of retval : %d\n", retval);
		printf("--> reading from the buffer : %s\n", buffer);
		close(fd1);
	}
}
