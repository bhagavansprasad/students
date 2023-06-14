#include "stdio.h"
int a[][4] = {
	{2, 4, 6, 8},
	{5, 7, 8, 2},
	{8, 9, 2, 1}
};

void dump_array(int (*p)[4])
{
}

int main()
{
	printf("Hello world\n");

	dump_array(a);
	return 0;
}

