#include<stdio.h>
int main()
{
	int n=5,i,j,k;
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=n-i+1;k++)
		{
			printf("%d",k);
		}
		printf("\n");
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
	}
}
