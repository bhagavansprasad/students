#include <stdio.h>
int main()
{
	int a=456,num = 0,rev;
		while(a>0)
		{
			rev = a % 10;
			num = num * 10 + rev;
			a = a / 10;
		}
	printf("num--->%d\n",num);
	return 0;
}
