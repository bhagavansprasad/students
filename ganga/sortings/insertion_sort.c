#include <stdio.h>	

void main()
{ 
	int a[5] = {5, 1, 4, 2, 8};

	int i, j, n = 5, temp = 0;

	for(i = 1; i <= n; i++)
	{
		temp = a[i];

		for(j = i-1; j >= 0 && temp < a[j]; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
	
	for(j = 0; j < n; j++)
	{
		printf("%d \n", a[j]);
	}
}
