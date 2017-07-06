#include "stdio.h"

int del_ele(int *a, int pos, int size)
{
	int i,j;

	printf ("del_ele: deleting :%d, elemement\n", pos);

	for(i = pos; i < size; i++)
		a[i] = a[i+1];

	return size-1;
}
