#include<stdio.h>
main()
{
	int a[2][2] = {1,2,3,4};
	int i, j;
	int *p[] = {(int *)a, (int *)a+1, (int *)a+2};
	for (i = 0; i<2; i++)
	{
		for(j = 0; j<2; j++)
		{
			printf("%d\t%d\t%d\t%d\n", *(*(p+i)+j), *(*(j+p)+i), *(*(i+p)+j),*(*(p+j)+i));
		}
	}
}
