#include<stdio.h>

int bit_count(unsigned int x)
{
	int b;
	for(b=0;x != 0; x >>= 1)
		if(x & 1)
			b++;
	return b;
}
int bit_count1(int n)
{
	int i;
	for( i = 0; (n = n &(n-1)) !=0;++i);
	return i;
}
		
main()
{
	printf(" no of bits in given no: %d \n",bit_count(6));
	printf(" no of bits in given no: %d \n",bit_count1(6));

}
