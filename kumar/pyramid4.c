#include<stdio.h>
int main()
{
	int i=1,j,n=5;
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%d",j);
		}
		{
			printf("\n");
		}
	}
}
