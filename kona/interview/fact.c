#include <stdio.h>
main()
{
	int n;
	printf("%d\n",fac(n));
}
int fac(int num)
{
	int fact=1,i,n=5;
	for(i=n;i>1;i--)
	{
		fact=fact*i;
	}
	return fact;
}
