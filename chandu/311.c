#include<stdio.h>
main()
{
	int i=1,n=5,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			printf(" ");
		}
		for(k=1;k<=n-i;k++)
		n--;	
		{
			printf("%d",k);
		}
		printf("\n");
	}

}

	
