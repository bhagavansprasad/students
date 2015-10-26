#include<stdio.h>
main()
{
	int i,n=3,sum=0,x;
	int fib(int a);
	for(i=1;i<=n;i++)
	{
		x=fib(i);
		sum+=x;
	}
	printf("sum of fibonacci terms:%d\n",sum);
}
int fib(int i)
{
	int y;
	if(i==1)
		return 0;
	if(i==2)
		return 1;
	if(i>2)
	{
		y=fib(i)+fib(i-1);
		return y;
	}

}
