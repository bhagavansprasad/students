#include <stdio.h>


static int showbits(int n);
int main()
{
	int i = 8;
	printf("decimal is same as bbinary%d\n",i);
	showbits(i);
    return 0;
}
static int showbits(int n)
{
int mask,i,k; 


	for(i=15;i>=0;i--)
	{
		mask=1<<i;
		k=n&mask;
		k==0?printf("0"):printf("1");
	}
	return 0;
}

