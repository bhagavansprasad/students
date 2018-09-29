#include <stdio.h>
void togglebit(int *pa, int pos);
void showbits(int num);

int main()
{
	int a=20;
	int pos=3;
	showbits(a);
	togglebit(&a, pos);
	showbits(a);
	togglebit(&a, pos);
	showbits(a);
	return 0;
}

void togglebit(int *pa, int pos)
{
	unsigned int mask = 1;
	mask = 1<<pos;
	*pa ^= mask;
}
