#include <stdio.h>
main()
{
	int i,j,n=5,p;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		printf(" ");
		p=n;
		for(j=1;j<=i;j++)
		printf("%d",p--);
		p=p+2;
		for(j=1;j<=i-1;j++)
		printf("%d",p++);
		printf("\n");
	}
}
