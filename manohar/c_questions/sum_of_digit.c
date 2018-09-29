#include <stdio.h>
int main()
{
	int a=456,sum = 0;
	while(a>0)
	{
		sum = sum + a % 10;
		a = a / 10;
	}
	printf("sum---->%d\n",sum);
	return 0;
}
