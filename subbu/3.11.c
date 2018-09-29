#include<stdio.h>
main()
{
	int i=1,n=5,k;
	int j=1,s;
	for(i=1;i<=n;i++)
	{
		for(s=1;s<i;s++)
		{
			printf(" ");
			for(j=1;j<=k;j++)
			{
				printf("%d",j);
			}
			k--;
			printf("\n");
		}
	
	}
}	
