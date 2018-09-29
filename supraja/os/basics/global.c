#include <stdio.h>
int a=10;
int main()
{
	printf("before the fork:%d\n",a);
	int pid;
	pid=fork();
	if(pid==0)
	{
		a++;
		sleep(5);
		++a;
		printf("im in child :%d\n",a);
	}
	else
	{
		printf("im in parent :%d\n",a);
	}
}
