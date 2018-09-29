#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
	void setbit(int *pa, int pos, bool l);

	int a=15, pos=2;
	printf("a -> %d\n", a);
	setbit(&a, pos, 0);
	printf("a -> %d\n", a);
	return 0;
}

void setbit(int *pa, int pos, bool l)
{
	unsigned int mask=1;
	if(l == 0)
		mask = 1<<pos;
	else
		mask = 0<<pos;
	*pa &= (~mask);
}
