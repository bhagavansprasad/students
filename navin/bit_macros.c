#include <stdio.h>
#include <stdlib.h>
#define MASK(POS) 1<<POS
#define SETBIT_OFF(N,POS) (N & ~(MASK(POS)))
#define SETBIT_ON(N,POS) (N | MASK(POS))
#define STATUS(N,POS) (N & MASK(POS))
void showbits(int num);

int main()
{
	int n=23, pos=7;
	showbits(n);
	n = SETBIT_ON(n,pos);
	showbits(n);
	n = SETBIT_OFF(n,pos);
	showbits(n);
	STATUS(n,pos) == 0 ? printf("status of %d bit -> 0\n",pos) : printf("status	of %d bit -> 1\n", pos);
	return 0;
}

void showbits(int num)
{
	int i,r;

	for(i=0;i<8;i++)
	{
		r=num&(1<<i);
		r==0 ? printf("0") : printf("1");
	}
	printf(" \n");


}

