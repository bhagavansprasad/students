#include <stdio.h>
main()
{
	int num=5,i,j,k=1;
	for(;num>=1;num--,k++)
	{ 
		for(i=1;i<=num;i++)
		{
			printf("%d",i);
		}
		for(j=k;j>1;j--)
		{
			printf(" ");
		}
		for(j=k;j>1;j--)
		{
			printf(" ");
		}
		for(i=num;i>=1;i--)
		{
			printf("%d",i);
		}
		printf("\n");
	}
}
