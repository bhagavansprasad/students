#include <stdio.h>
#include <fcntl.h>

main()
{
	int pid , fd , retval;
	pid=fork();
	char buff[100]="hello hello hello";

	fd=open("temp.txt" , O_CREAT | O_RDWR);
	printf("fd: %d",fd);

	if(pid==0)
	{
		fd=open("temp.txt" , O_CREAT | O_RDWR);
		retval=	write(fd , buff , 10);
		printf("%s\n",buff);
		//printf("child process\n");
		close(fd);
	}
	else
	{
		fd=open("temp.txt" , O_CREAT | O_RDWR);
		retval=read(fd , buff , 7);
		printf("%s\n",buff);
		//printf("parent process\n");
		close(fd);
	}
}

