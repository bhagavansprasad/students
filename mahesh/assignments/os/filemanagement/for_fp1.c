#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,pid,len = 10,rval;
	char buff[100];
	fd = open("a.txt",O_RDONLY);
	pid = fork();
	if(pid > 0)
	{
		printf("----> IN PARENT <-----\n");
		printf("fd is : %d\n",fd);
		rval = read(fd,buff,len);
		buff[rval] = '\0';
		printf("%s\n",buff);
//		close(fd);
	}
	else if(pid == 0)
	{
		int i = 0;
		printf("----> IN CHILD <-----\n");
		printf("fd is : %d\n",fd);
		{
			rval = read(fd,buff,len);
			buff[rval]= '\0';
		while(1)
			printf("%s\n",buff);
			//lseek(fd,-10l,1);
		//	i++;
		}
	}
}
