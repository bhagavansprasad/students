#include <stdio.h>
main()
{
	int num=538769,sum,c;
	do
	{
		sum=0;
		while(num!=0)
		{
			c=num%10;
			sum=sum+c;
			num=num/10;
		}
		printf("%d\t",sum);
		num=sum;
	}while(num/10!=0);
}
