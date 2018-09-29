#include <stdio.h>
void displayBits(int x);
int main(void)
{
	unsigned n=140;
	displayBits(n);
	n=n&(n-1);
	displayBits(n);
	return 0;
}
