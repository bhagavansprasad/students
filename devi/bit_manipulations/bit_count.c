#include <stdio.h>

void get_bit_count(int a)
{
	int countzero=0,countone=0,i,n;
	for(i=0;i<8;i++)
	{
		n = a & (1 << i);
		if(n == 0)
		countzero++;
		else
		countone++;
	}
	printf("no .of 1's in %d is %d\n", a,countone);
}
main()
{
	int a=10;
	get_bit_count(a);
}
