#include <stdio.h>
#include <fcntl.h>

main()
{
	int pid ,fd ;
	char buff[100]="Hello Aura";
	char arr[40];

	fd=open("dupli.txt" , O_CREAT | O_RDWR);
	
	pid=fork();

	if(pid == 0)
	{
		int retval;
		retval=	write(fd, buff,100);
		printf("retval=%d\n",retval);
		close(fd);
	}
	else
	{
		int ret;
		sleep(2);
		fd=open("dupli.txt" , O_RDWR);
		ret=read(fd, arr,100);

		printf("ret=%d\n",ret);

		arr[ret]='\0';
		printf("%s\n",arr);
	}
}

