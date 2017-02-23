#include<stdio.h>
int fact(int);
main()
{
	int sum=0,i=1,n=5;
	for(i=1;i<=n;i++)
	{
		sum=sum+fact(i);
	}
	printf("sum of factorial is=%d\n",sum);
}
int fact(int a)
{
	int f=1,j=1;
		for(j=1;j<=a;j++)
		{
			f=f*j;
		}
	return f;
}
