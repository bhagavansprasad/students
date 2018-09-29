#include <stdio.h>
#include <fcntl.h>
main()
{
	int len = 5;
	char buff[1024];
	int fd=open("a.txt",O_RDONLY);
	int fd2 = open("b.txt",O_CREAT|O_RDWR,0644);
	if(fd==-1)
		printf("error in opening a file read mode\n");
	if(fd2==-1)
		printf("error in opening a file create mode\n");
	while(1)
	{
		int rval = read(fd,buff,len);
		buff[rval]='\0';
		write(fd2,buff,rval);
		if(rval<len)
			break;
	}
	printf("\n");
}
