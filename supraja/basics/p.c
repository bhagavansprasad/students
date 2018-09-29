#include"stdio.h"
#include<fcntl.h>
main()
{
	int i,n=5,j;
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",j);
		}
		printf("\n");
		n--;
	
	}
}
