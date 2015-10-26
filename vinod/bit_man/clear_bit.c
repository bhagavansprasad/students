#include <stdio.h>
#define NUMBER 20
#define POSITION 4

void showbits(int num);
void clear_setbit(int *num, int pos);

int main()
{
	int n = NUMBER, pos = POSITION;
	printf("The binary form of %2d before clearing %dth pos is --> ", NUMBER, pos);
	showbits(n);
	clear_setbit(&n, pos);
	printf("\nThe binary form of %2d after clearing %dth pos is ---> ", NUMBER, pos);
	showbits(n);
	printf("\n");
	return 0;
}

void clear_setbit(int *num, int pos)
{
	unsigned int mask=1,k;
	mask <<= pos;
	*num &= (~mask);
}
