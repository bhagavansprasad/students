#include<stdio.h>
main()
{
	int n=5,i,j,k,count=0;
	for(i=5;i>0;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		count++;
		printf("\n");
		for(k=1;k<=count;k++)
		{
			printf(" ");
		}
	}
}
