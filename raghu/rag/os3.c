#include <stdio.h>
main()
{
	int pid,fd,rfd,wfd,cfd;
	char buff[100];
	pid = fork();
	if(pid == 0)
	{
		fd = open("t.txt",O_RDONLY,0);
		printf("the return value of the open in child is =%d\n",fd);
		rfd = read(fd,buff,10);
		printf("the value of the in child is =%d\n",buff);
		close(fd);
	}
	
	
}
