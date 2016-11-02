#include<stdio.h>
void main()
{
	int i,j,n=5,z=1;
	for(i=1;i<=n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
		  printf(" ");
		}
		for(j=1;j<=z;j++)
		{
		  printf("%d",j);
		}
		z++;
		printf("\n");
	}
}


