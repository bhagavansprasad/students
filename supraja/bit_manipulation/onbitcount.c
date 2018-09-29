#include<stdio.h>
int main()
{
	unsigned int a=10;
	on_bit_count(a);
}

int on_bit_count(int  n)
{
	unsigned int mask;
	int pos;
	unsigned int c;
	int k=0;
	for(pos=7;pos>=0;pos--)
	{
		mask=1<<(pos);
		c=n&mask;
		if(c!=0)
		{
			k=k+1;
		}
	}
	printf("%d\n",k);
}
