#include <stdio.h>
#include<fcntl.h>

int a=10;

main()
{	
	int pid,fd;
	char buff[100] = "hi how are you";
	char arr[50];

	fd=open("temp.txt",O_CREAT |O_RDWR);

	pid=fork();

	if(pid == 0)
	{
		int retval=	write(fd, buff, 100);
		printf("C: retval %d\n", retval);
		close(fd);
	}
	else
	{
		int retval;

		sleep(2);
		fd = open("temp.txt", O_RDWR);
		retval=read(fd, arr, 100);

		printf("P:\n");
		printf("P: retval %d\n", retval);

		arr[retval]='\0';
		printf("P: %s\n", arr);
	}
}
