#include<stdio.h>
main()
{
	int n=10,t=0,sum=0,count=0,i;
	for(i=1;count<n;i++)
	{
		t=get_prime(i);
		sum=sum+t;
		if(t>0)
		{
			printf("%d\n",t);
			count++;
		}
		if(count==n)
		{
			printf("%d",sum);
		}
	}
}
int get_prime(int x)
{
int j;
for(j=2;j<=(x-1);j++)
{
if(x%j==0)
{
return(0);
}
}
if(j>=x)
{
return(x);
}
}
