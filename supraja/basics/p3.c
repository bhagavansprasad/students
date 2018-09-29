#include"stdio.h"
main()
{
	int i,j,n=5,k;
	for(i=4;i>=n-1;i++)
	{
		for(k=1;k<=i;k++)
		{
			printf(" ");
		}
		for(j=1;j<=n-i;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
