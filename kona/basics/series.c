#include <stdio.h>
main()
{
	int i,sum=0,term=1,n=6;
	for(i=1;i<=n;i++)
	{
		sum=sum+term;
		term=term+i;
	}
		printf("--->val is : %d\n",sum);
}
