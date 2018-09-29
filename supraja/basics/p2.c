#include"stdio.h"
main()
{
	int i,n=5,j,x=5;
	for(i=n;i>=n-x;i--)
	{
		printf("");
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	}
