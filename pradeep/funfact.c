#include <stdio.h>
int main()
{
	int n=5,t;
	t=factorial(n);
		printf("%d",t);
}
int factorial(int num)
{
	int i=1,f=1;
	for(i=1;i<=num;i++)
	{
		f=f*i;
	}
	return f;
}
