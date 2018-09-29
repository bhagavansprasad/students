#include<stdio.h>
main()
{
	int i,j,n=5;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(j<=i)
			{
				printf("%d",j);
			}
			else
				printf(" ");
		}
		for(j=4;j>=1;j--)
		{
			if(j<=i)
			{
				printf("%d",j);
			}
			else
				printf(" ");
			}	
				printf("\n");
				
	}
}
