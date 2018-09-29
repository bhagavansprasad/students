#include <stdio.h>
int i =6;
main()
{
	int fd;
	fd = fork();
	if(fd == 0)
	{
		i++;
		printf("%d\n", i);
	}
	else
	{
		i = i+2;
		printf("%d\n",i);
	}
}
