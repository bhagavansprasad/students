#include<stdio.h>
int main()
{
	unsigned int a=10;
	unsigned int b=3;
	showbits(a);
	a=set_bit_off(a,b);
	showbits(a);
}
int set_bit_off(int n,int pos)
{
		n=n&1<<pos;
	if(n!=0)
	{
		n=n^1<<pos;
	}
		return n;
}

