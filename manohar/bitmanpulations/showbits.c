#include <stdio.h>
int main()
{
	int n=30;
	showbits(n,31);
	n = set_bit(n,7);
	showbits(n,31);
	n = reset_bit(n,3);
	showbits(n,31);
	n = toggle_bit(n,13);
	showbits(n,31);
	return 0;

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
int showbits(int n,int p)
{
	int i;
	for(i=p;i>=0;i--)
	{
		if(n & (1<<i))
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
}
