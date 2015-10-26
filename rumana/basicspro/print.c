#include<stdio.h>
main()
{
	int i,j,k;

	for(i=1;i<=5;i++)
	{
		if(i==2)
		{
			for(k=1;k<=i;k++)
				printf("%d",k);
			printf("\n");
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		for(j=i-1;j>=1;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
