#include<stdio.h>
main()
{
	int i,k,j,n=5,s=0;
	for(i=n;i>=1;i--)
	{
			for(k=1;k<=s;k++)
		{
			printf(" ");
		}
                  s++;
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
	printf("\n");

	}
}



