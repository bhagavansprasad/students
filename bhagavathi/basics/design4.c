#include <stdio.h>
main()
{
	int i,j,n=5,s,k=1,m=4;
	for(i=1;i<=n;i++)
	{
		for(s=1;s<=m;s++)
		{
			printf(" ");
		}
		for(j=1;j<=k;j++)
		{
			printf("%d",j);
		}
		printf("\n");
		m--;
		k++;
	}
}
