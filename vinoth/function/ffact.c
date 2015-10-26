#include<stdio.h>
main()
{
	int fact=1, i=1, n=10, x=0;
	for (i=1; i<=n; i++)
	{
		fact=fact*i;
		printf("%d!=%d\n", i, fact);
		x=x+fact;
	}
	printf("%d\n",x);
}

