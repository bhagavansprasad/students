#include<stdio.h>
main()
{
	int i=1,n=5,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf("%d",j);
		}
		printf("%d\n",j);
	}
}
