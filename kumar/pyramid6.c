#include<stdio.h>
int main()
{
	int i=1,j=1,k=4,m=1,p=1,q=4,n=5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",i);
		}
		for(k=4;k>0;k--)
		{
			printf("%d",k);
		}
		for(m=1;m<=n-i;m++)
		{
			printf("%d",m);
		}
		for(p=1;p<i;p++)
		{
			printf("%d",p);
		}
		for(q=4;q>0;q--)
		{
			printf("%d",q);
		}
		printf("\n");
	}
}

