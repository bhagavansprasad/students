#include <stdio.h>
main()
{
	int i,j,s,n=5,k=5;
	for(i=1;i<=n;i++)
	{
		for(s=1;s<=(k-1);s++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		k--;
		printf("\n");
	}
}
