#include<stdio.h>
int main()
{
	int i,f=1,n=5,t=0 ;
	for(i=1;i<=n;i++)
	{
		t=fact(i);
		{
			printf("%d",t);
			printf("\n");
		}
	}
}
int fact(int x)
{
	int i,f=1;
	for(i=1;i<=x;i++)
	{
		f=f*i;
	}
	return f;
}

