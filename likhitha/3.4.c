#include<stdio.h>
int main()
{
	int n=10,i,count=1,t;
	for(i=2;count<=n;i++)
	{
		t=is_prime(i);
		if(t==1)
		{
			printf("%d\n",i);
			count++;
		}
	}
}
int is_prime(int n)
{
	int i;
	for(i=2;i<=(n-1);i++)
	{
		if(n%i==0)
			break;
	}
	if(i==n)
		return 1;
	else 
		return 0;
}

