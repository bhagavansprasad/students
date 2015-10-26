#include<stdio.h>
main()
{
	int i,a,b,k=1,j,n=8,x,c=0;
	b = x = n;
	for(a=1;a<=b;a++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",i);
		}
		for( ;k>=2;k--)
		{
			printf(" ");
		}
		for(j=n;0<j && j<=x;j--)
		{
			printf("%d",j);
		}
		n--;
		x--;
		c=c+2;
		k=c+1;
		printf("\n");
	}
}

