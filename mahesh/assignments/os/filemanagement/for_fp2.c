#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,rval = 0,len = 10;
	char buff[100];
	int i =0;
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
