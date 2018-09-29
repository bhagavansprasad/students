#include <stdio.h>
main()
{
	int i,j,n=15,x=0;
	for(i=2;i<n;i++)
	{
		for(j=2;i%j!=0;j++);
		if(j==i)
		{
			printf("%d\t",i);
			x=x+i;
		}
	}
		printf("%d\n",x);
}
