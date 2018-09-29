#include <stdio.h>
void showbits(int num);
int main()
{
	int a=31, b=0;
	printf("Before reverse\n");
	showbits(a);
	b = revbits(a);
	printf("After reverse\n");
	showbits(b);
	return 0;
}

int revbits(int num)
{
	unsigned int mask = 1;
	unsigned int NO_OF_BITS = sizeof(num)*8;
	int revno=0;
	int i;
	for(i=0 ; i<NO_OF_BITS ; i++)
	{
		mask = 1<<i;
		if(num & mask)
			revno |= 1 << (NO_OF_BITS-1-i);
	}
	return revno;
}
