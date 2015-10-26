#include <stdio.h>
int get_bit_value(int n);
main()
{
	int n=8;
	get_bit_value=showbits(n);
}
int get_bits_value(int n,int pos,int nob)
{
	int i,k,mask;
	for(i=6;i>=3;i--)
	{
		mask=1<<i;
		k=n&mask;
		if(k!=0)
		return 1;
		else
		return 0;
	}
}
