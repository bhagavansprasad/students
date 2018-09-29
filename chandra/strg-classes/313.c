#include<stdio.h>
main()
{
	int i,j,k,n=5,c=5;
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
