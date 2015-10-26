#include <stdio.h>
main()
{
	int a=0,b=1,c,i,n=10;

	printf("printing the fibonacci series\n");
	printf(" %d %d ",a,b);
	for(i=2;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		printf(" %d ",c);
	}
	printf("\n");
}
