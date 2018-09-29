#include <stdio.h>
int swapEvenOddBits(int n)
{
	int i,b;
	printf("before swapping\n");
   	for(i=7;i>=0;i--)
	{
		b = n&(1<<i);
		if(b==0)
		printf("0");
		else
		printf("1");
	}
	printf("\n");
//	n = (((n&0x55)<<1)|((n&0xAA)>>1));
	printf("%d\n",n);
	return n;
}
main()
{
	int a = 7,c,i,d;
	c = swapEvenOddBits(a);
	printf("After swapping\n");
	for(i=7;i>=0;i--)
	{
		d = c&(1<<i);
		if(d == 0)
		printf("0");
		else
		printf("1");
	}

}
