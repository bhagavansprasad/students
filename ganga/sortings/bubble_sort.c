#include <stdio.h>	

void main()
{ 
	int a[5] = {5, 1, 4, 2, 8};

	int i, j, n = 5, temp = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(j = 0; j < n; j++)
	{
		printf("%d \n", a[j]);
	}
}
