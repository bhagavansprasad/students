#include<stdio.h>
main()
{
	int n=5,i,j,c=5,k;
	for(i=1;i<=n;i++)
	{
		c--;
		for(k=1;k<=c;k++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
