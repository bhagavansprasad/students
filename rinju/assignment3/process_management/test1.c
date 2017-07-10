
#include <stdio.h>
int a=10;
main()

{
	int pid;
	pid=fork();
	if(pid == 0)
	{
		//while(1)
		{
			printf("i am child\n");
			printf("a = %d\n",a);
		}
	}
	else
	{
		//while(1)
		{
			printf("i am parent\n");
			a++;
			printf("a = %d\n",a);
		}
	}
}
