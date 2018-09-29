#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd=open("t.txt",O_RDONLY);
	int a=fork();
	if (a>0)
		printf("----fd:%d\n",fd);
	else
		printf("----fd:%d\n",fd);

}
