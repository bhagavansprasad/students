#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,rval = 0,len = 10;
	char buff[100];
	pid = fork();
	if(pid > 0)
	{
		printf("----> IN PARENT <----\n");
		fd = open("a.txt",O_RDONLY);
		printf("fd is : %d\n",fd);
		rval = read(fd,buff,len);
		buff[rval] = '\0';
		printf("%s\n",buff);
	}
	else if(pid == 0)
	{
		int i =0;
		printf("----> IN CHILD <----\n");
		fd = open("a.txt",O_RDONLY);
		printf("fd is : %d\n",fd);
		{
			rval = read(fd,buff,len);
			buff[rval] = '\0';
		while(1)
			printf("%s\n",buff);
			//lseek(fd,-10l,1);
			i++;
		}
	}
}
