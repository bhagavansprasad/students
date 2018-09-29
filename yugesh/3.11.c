#include <stdio.h>
main()
{
	int i,n=5,s,j;
	for(i=1;i<=n;i++)
	{
		for(s=0;s<i;s++)
		{
			printf(" ");
		}
		for(j=1;j<=(n-i)+1;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
