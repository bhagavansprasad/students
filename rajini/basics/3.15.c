#include <stdio.h>
main()
{
	int i=0,j=0,k=0,n=5;
	for(i=1;i<=n;i++)
	{

		for(j=0;j<=i;j++)
		{
			printf("%d",j);
		}
		for(k=n-i;k<[(n-i)*2]-1;k++)
		{
			printf(" ");
			for(i=1;i<=i;i++)
			{
				printf("%d",i);
			}
		}
	}
}
