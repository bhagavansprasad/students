#include <stdio.h>
int fun(int,int);
main()
{
	int c;
	c = fun(2,3);
	printf("%d\n", c);
	int fun(int a,int b)
	{
		return (a+b);
	}
//	return 0;
}
