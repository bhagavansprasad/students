#include<stdio.h>

int show_bits(int num)
{
	int i;
	for(i=31 ; i>= 0; i--)
	{
		(num & (1<<i))? printf("1"):printf("0");
	}
	printf("\n");

}

main()
{
	show_bits(10);
}
