#include <stdio.h>
int main()
{
	int a=10,pid;
	printf("address of a is :%u\n",&a);
	pid=fork();
	if(pid==0)
	{
		printf("Iam in child");
		printf("address of a is :%u\n",&a);
		a++;
		printf("increment value child :%d\n",a);
		sleep(5);
	}
	else
	{
		printf("Iam in parent");
		printf("address of a is :%u\n",&a);
		printf("increment value in parent:%d\n",a);
	}
}
