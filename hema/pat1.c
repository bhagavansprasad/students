#include<stdio.h>
main()
{
	int i,j;
	for(i=1;i>=1;i++)
	{
    for(j=1;j<=5;j++)
	{
		if(j<=i)
			printf("%d",j);
			else
    		printf(" ");
	}
	for(j=4;j>1;j--)
	{
		if(j<=i)
		printf("%d",j);
		else
		printf(" ");
	}
	printf("%d",j);
	printf("\n");
	}
}




