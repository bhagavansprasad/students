#include <stdio.h>
main()
{
	int p[2],retval ,pid;
	char buff[20]="hi how are you";
	char arr[20];
	retval = pipe(p);
	pid = fork();
	if(pid >0)
	{
		close(p[0]);
		write(p[1],buff,20);

	}
	else {
		close(p[1]);
		read(p[0],arr,20);
		printf("%s\n",arr);
	}

}
