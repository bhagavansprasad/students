#include <stdio.h>

void main()
{
	int a[5] = { 5, 1, 4, 2, 8};
	
	int i, n = 5, c;
	
	for( i = 0; i <= n-1; i++)
	{
		if(a[i] == 2)
		{
			c = 1;
			break;
		}
	}
	
	if(c == 0)
	{
		printf(" the element is not in the given array ");
	}
	
	else 
	{
		printf("element %d is found in the given array at index %d  \n",2, i);
	}
}
