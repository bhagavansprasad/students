#include<stdio.h>
int main()
{
	int n=5,i,j;
	for(i=1 ; i<=n ; i++)
	{
		printf(" %d",i);
	}
	for(j=(n-1);j>0;j--)
	{
		printf(" %d",j);
	}
	printf("\n");
}
