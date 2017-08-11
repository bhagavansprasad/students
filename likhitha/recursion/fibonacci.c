#include<stdio.h>
void main()
{
	int i,r,n=5;
	for(i=1 ; i<=n ;i++)
	{
		r=fib(i);
		printf(" %d ",r);
	}
	printf("\n");
}

int fib(int x)
{
	int f;
	if (x==1)
		return(0);

	else if (x==2)
		return(1);

	else
		f= fib(x-1)+fib(x-2);

	return(f);
}
