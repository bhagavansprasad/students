#include<stdio.h>
int main()
{
	int a=1,i,c=1,sum=0,t=0,n=10;
	for(i=a;c<=n;i++)
	{
		t=isprime(i);
		if(t==1)
		{
		sum=sum+i;
			printf("%d\n",i);
			c++;
		}
	}
	printf("%d\n",sum);
}
int isprime(int b)
{
	int i;
	for(i=2;i<=b-1;i++)
	{
		if(b%i==0)
		{
			return 0;
			break;
		}
	}
	if(i==b)
	{
		return 1;
	}
}
