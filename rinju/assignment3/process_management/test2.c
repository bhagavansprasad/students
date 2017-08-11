
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
			a++;
			printf("a = %d\n",a);
			printf("address =%u\n",&a);
		}
		sleep(1);
	}
	else
	{
		//while(1)
		{
			printf("i am parent\n");
			
			printf("a = %d\n",a);
			printf("address =%u\n",&a);
		}
		sleep(1);
	}
}
