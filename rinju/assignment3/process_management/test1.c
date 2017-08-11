
#include <stdio.h>
int a=10;
main()

{
	int pid;
	pid=fork();
	if(pid == 0)
	{
		
			printf("i am child\n");
			printf("a = %d\n",a);
		
	}
	else
	{
		
			printf("i am parent\n");
			a++;
			printf("a = %d\n",a);
		
		}
}
