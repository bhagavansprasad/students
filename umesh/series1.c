#include<stdio.h>
main()
{
	int i,j,n=5,x=5;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=x;j++)
		{
			printf("%d",j);
		}
		x--;
		printf("\n");
	}
}
