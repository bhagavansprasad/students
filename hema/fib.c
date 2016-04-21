#include<stdio.h>
void main()
{
	int fib1=0,fib2=1,fib3,count=0,n,sum=0;
	printf("enter the nuum");
	scanf("%d",&n);
	count=2;
	while(count<n)
	{
		fib3=fib1+fib2;
		count++;
		fib1=fib2;
		fib2=fib3;
		sum=sum+fib3;
	}
		printf("%d",sum);
}
