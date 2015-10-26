#include "stdio.h"
main()
{
	int i,j,n=5,k;
	for(i=0;i<n;i++)
	{
		for(k=0;k<n-i-1;k++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
			printf("%d",fact(i)/(fact(j)*fact(i-j)));
			printf("\n");
	}
	return 0;
}
int fact(int n)
{
	long f=1;
	int i=1;
	while(i<=n)
	{
		f=f*i;
		i++;
	}
	return(f);
}
