#include<stdio.h>
main()
{
	int i, a = -1, b = 1, c = 0, n=10;
	for(i = 0 ; i < n ; i++)
	{
		c= a+b;
		a = b;
		b = c;
		printf("%d\t", c);
	}
	printf("\n");
}
