#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd , pid,len = 10, retr = 0,retw = 0 ;
	char buff[21];
	fd = open ("t.txt" , O_RDWR,0777);
	pid = fork();
	/*
	if(pid == 0)
	{
		close(fd);
	}
	else
	{
		retr = read (fd , buff , len);
		printf("parent retr %d \n parent retr buff %s \n",retr, buff);
		retw = write (fd ,buff ,retr);
		printf("parent retw %d \n parent retw buff %s \n",retw, buff);
	}
	*/
		if(pid == 0)
	{
		retr = read (fd , buff , len);
		printf("parent retr %d \n parent retr buff %s \n",retr, buff);
		retw = write (fd ,buff ,retr);
		printf("parent retw %d \n parent retw buff %s \n",retw, buff);

	}
	else
	{
				close(fd);

	}


}
