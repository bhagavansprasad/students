#include<stdio.h>
int fibo(int n)
{
	int c,i=0,j=1,a=1,k;
	for(k=0;k<n;k++)
	{
		c=i+j;
		i=j;
		j=c;
		a++;
		return c;
	}
}
main()
{
	int x = 10;
	for()
	{
		int get = fibo(x);
		printf("%d",get);
	}
}
