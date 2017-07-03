#include <stdio.h>
main()
{
	static int a=50;
	int new_fun()
	{
		printf("a=%d",a);
		a++;
		printf("a=%d",a);
	}
}
