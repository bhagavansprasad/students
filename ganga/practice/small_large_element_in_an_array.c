#include <stdio.h>

void main()
{
	int a[7] = {80, 100, 20, 15, 30, 75, 85};

	int small = 80, large = 80;
	int i, j, k;

	for(i = 0 ; i < 7 ; i++)
	{

		if(a[i] < small)
		{
			small = a[i];
			j = i;
		}

		else if(a[i] > large)
		{
			large = a[i];
			k = i;
		}
	}

	printf("small :%d\t index :%d\n", small, j);
	printf("large :%d\t index :%d\n", large, k);
}
