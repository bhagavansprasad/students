#include <stdio.h>
main()
{
	int i,j,n=5,k;
	for(i=1;i<=n;i++)
	{
	for(k=n;k>i;k--)
		{
		printf("-");
		}
	for(j=1;j<=i;j++)
	{
	printf("%d",j);
	}
	printf("\n");
	}
}
