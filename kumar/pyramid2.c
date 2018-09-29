#include<stdio.h>
int main()
{
	int i=1,j=1,k=1,n=5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)
		{
			printf("%d",k);
		}
		printf("\n");
	}
}
