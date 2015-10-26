#include<stdio.h>
main()
{
	int n=5,i=0,j=0;
	for(i=5;i>0;i--)
	{
		for(j=1;j<=(n-i+1);j++)
		{
			printf("%d",j);
		}
		printf("\n");
		}
}
