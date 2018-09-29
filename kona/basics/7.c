#include <stdio.h>
main()
{
	int i,j;
	for(i=0;i<=5;i++)
	for(j=0;j<=5;j++)
	{	
		if(j==0)
			printf("%d",i+1);
			else
			printf("%d",i+2);
		if(j==0)
		printf("%d",i+2);
		else
		printf("%d",i);
	}
	
}
