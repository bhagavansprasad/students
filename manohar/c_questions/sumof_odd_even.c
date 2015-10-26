#include <stdio.h>
int main()
{
	int n[10]={1,2,3,4,5,6,7,8,9,10};
	int i,sum_even=0,sum_odd=0;
	for(i=0;i<10;i++)
	{
		if(n[i]%2==0)
		{
			sum_even = sum_even + n[i];
		}
		else
		{
			sum_odd = sum_odd + n[i];
		}
	}
	printf("sum of even numbers is %d\n",sum_even);
	printf("sum of odd numbers is %d\n",sum_odd);
	return 0;
}
