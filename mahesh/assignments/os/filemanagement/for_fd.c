#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,len = 10,rval = 0;
	char buff[100];
	fd = open("a.txt",O_RDONLY);
	pid = fork();
	if(pid > 0)
	{
		//fd = open("a.txt",O_RDONLY);

		printf("-----> IN PARENT <-----\n");
		printf("parent fd is : %d\n",fd);
		printf("reading in parent \n");
		rval = read(fd,buff,len);
		buff[rval] = '\0';
		printf("%s\n",buff);
		printf("in parent closing of fd\n");
		close(fd);
	}
	else if(pid == 0)
	{
		//fd = open("a.txt",O_RDONLY);
		printf("---> IN CHILD <-----\n");
		printf("child fd is :%d\n",fd);
		printf("reading in child \n");
		rval = read(fd, buff, len);
		buff[rval] = '\0';
		printf("%s\n",buff);
//		close(fd);
	}
}
