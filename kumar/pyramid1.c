#include<stdio.h>
int main()
{
	int i=0,n=5,j=1;
	for(i=0;i<=n;i++)
	{
		for(j=1;j<n-4+i;j++)
		{	
			printf("%d",j);
		}
		printf("\n");
	}
}
