#include <stdio.h>
main()
{
	int i,n=5,j,k,m,f;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)
		{
			printf("%d",k);
		}
		for(f=i;f>=i;f++)
		{
		printf("%d",f);
		}
		printf("\n");
	}
}
