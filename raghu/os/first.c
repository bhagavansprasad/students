#include <stdio.h>
int a = 10;
main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		int a =20;
		printf("In child =%d\n",a);
		printf("In child =%d\n",getpid());

	}
	else
	{
		printf("In parent =%d\n",a);
		printf("In child =%d\n",getppid());
	}
}
