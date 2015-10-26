#include <stdio.h>
void setbiton(int *pa, int pos);
void showbits(int num);
int main()
{
	int a = 20;
	int pos = 3;
	showbits(a);
	setbiton(&a, pos);
	showbits(a);
}

void setbiton(int *pa, int pos)
{
	unsigned int mask = 1;
	mask = 1<<pos;
	*pa |= mask;
}
