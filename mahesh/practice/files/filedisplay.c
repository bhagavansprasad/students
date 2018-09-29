#include <stdio.h>
#include <fcntl.h>
main()
{
	int len = 5;
	char buff[1024];
	int fd=open("a.txt",O_RDONLY);
//	int fd2 = open("b.txt");
	if(fd==-1)
		printf("error in opening a file\n");
	while(1)
	{
		int rval = read(fd,buff,len);
		buff[rval]='\0';
		printf("%s",buff);
		if(rval<len)
			break;
	}
	printf("\n");
}
