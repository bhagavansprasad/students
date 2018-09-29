#include <stdio.h>
main()
{
	int p[2];
	int retval ,pid;
	char buff[20]="Hello Hello Hello";
	char arr[20];

	retval = pipe(p);

	pid = fork();

	if(pid == 0)
	{
		close(p[0]);
		write(p[1],buff,20);

	}

	else
	{
		close(p[1]);
		read(p[0],arr,7);
		printf("%s\n",arr);
	}
}
