#include <stdio.h>
main()
{
	int n=789988;
	do
	{
		int sum=0,rem;
		while(n!=0)
		{
			rem=n%10;
			n=n/10;
			sum=sum+rem;
		}
		printf("sum value is %d\n",sum);
		n=sum;
	}while(n/10!=0);
}
