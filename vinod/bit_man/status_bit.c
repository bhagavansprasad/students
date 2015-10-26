#include <stdio.h>
#include <stdbool.h>
bool statusbit(int num, int pos);
void showbits(int num);

int main()
{
	int a=25;
	int pos=2;
	bool b=0;

	showbits(a);
	b = statusbit(a, pos);
	printf("Status of %d position bit -> %d\n", pos, b);
	return 0;
}

bool statusbit(int num, int pos)
{
	unsigned int mask = 1;
	mask = 1<<pos;
	return num & mask;
}
