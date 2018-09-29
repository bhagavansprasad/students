#include <stdio.h>
int a=10;
main()
{
	int a=20;
	int i=5;
	printf("a=%d",a);
	if(i>3)
	{
		int a=30;
		printf("a=%d",a);
		a++;
	}
	printf("a=%d",a);
}
