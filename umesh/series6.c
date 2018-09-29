#include<stdio.h>
main()
{
	int i,a,b=5,k,j,m=5,n=2;
	for(a=1;a<b;a++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",i);
		}
		for(k=1;k<=m;k++)
		{
			printf(" ");
		}
		for(j=n;0<j && j<=5;j--)
		{
			printf("%d",j);
		}
		n=n+1;m=m-2;
	    printf("\n");
	}
}	
