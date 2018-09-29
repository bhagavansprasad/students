#include <stdio.h>
main()
{
	int i,j,n=5,k=5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			printf("%d",j);
		}
		k--;
		printf("\n");
	}
}
