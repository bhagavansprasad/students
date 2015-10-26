#include<stdio.h>
void show_bits(unsigned int n)
{
	unsigned char c,mask;
	int i;
	static int statvar = 0;


	if (statvar == 0)
	{
		printf("%8s", "");
		for(i = sizeof(n) * 8; i >= 0; i--)
		{
			printf("%3d", i);
		}
		printf("\n");
		statvar = 1;
	}
	printf("%5d-->", n);
	for(i = sizeof(n) * 8; i >= 0; i--)
	{
		mask = 1 << i;
		c = n & mask;
		printf("%3d", (c == 0 ? 0 : 1));
#if 0
		mask = 1 << i;
		c = n & mask;
		c == 0 ? printf("0"): printf("1");
#endif
	}

	printf("\n");
}

//void show_bits(unsigned int n)
int main()
{
	unsigned int a=10;

	show_bits(10);
	show_bits(300);
	show_bits(1000);
}

