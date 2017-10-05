#include <stdio.h>
int main()
{
	//int n=300;
	float n=10.0;

	showbits((unsigned int *)&n, 31);
#if 0
	showbits(n,31);
	n = set_bit(n,7);
	showbits(n,31);
	n = reset_bit(n,3);
	showbits(n,31);
	n = toggle_bit(n,13);
	showbits(n,31);
	return 0;
#endif

}
int set_bit(int n,int pos)
{
	int k;
	k = n | (1<<pos);
	return k;
}
int reset_bit(int n,int pos)
{
	int k;
	k = n & (~(1<<pos));
	return k;
}
int toggle_bit(int n,int pos)
{
	int k;
	k = n ^ ((1<<pos));
	return k;
}
int showbits(unsigned int *p, int size)
{
	int i;
	for(i=size;i>=0;i--)
	{
		if((*p) & (1<<i))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	for(i=0;i<=size;i++)
	{
		if((*p) & (1<<i))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

}
