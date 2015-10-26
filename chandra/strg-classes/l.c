#include<stdio.h>
int a=10;
main()
{
	int a=20;
	int i=5;
	printf("%d\n", a);
	if(i>3)
	{
		int a=30;
		printf("%d\n", a);
		a++;
	}
	printf("%d\n", a);
}
