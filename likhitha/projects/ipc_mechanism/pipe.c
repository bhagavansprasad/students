#include <stdio.h>
#include <fcntl.h>

main()
{
	int pid , fd ;
	char buff[100]="hello hello hello";
	char arr[40];

	fd=open("dupli.txt" , O_CREAT | O_RDWR);
	pid=fork();

	if(pid==0)
	{
		int	retval=	write(fd, buff, 100);
		printf("%d\n",retval);
		close(fd);
	}
	else
	{
		int ret;
		sleep(1);
		fd=open("dupli.txt" , O_RDWR);
		ret=read(fd, arr, 7);

		printf("%d\n",ret);

		arr[ret]='\0';
		printf("%s\n",arr);
	}
}

