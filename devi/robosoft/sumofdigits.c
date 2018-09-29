#include <stdio.h>
main()
{
	int a = 8123;
	int n=a,sum=0;
	while(n>0)
	{
		sum = sum + (n%10);
	printf("sum-->%d\n",sum);
		n = n/10;
	}
	printf("a-->%d\tsum-->%d\n",a,sum);
}

