#include <stdio.h>
main()
{
	printf("the bit value is =%d\n",get_bit_value(10 , 3));
}

int get_bit_value(int n,int pos)
{
	int c;
	int mask;
	mask = 1<<(pos-1);
	c = n & mask;
	if(c==0)
	return 0;
	else 
	return 1;
}



