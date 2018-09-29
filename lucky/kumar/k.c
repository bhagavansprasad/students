#include<stdio.h>
int main()
{
	int i,j,k,n=5;
	for(i=4;i>0;i--)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%d",j);
		}
		for(k=1;k<=2*i-1;k++)
		{
			printf(" ");
		}
		for(j=n-i;j>0;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
	}
	for(j=4;j>0;j--)
	{
		printf("%d",j);
	}
	printf("\n");
}
