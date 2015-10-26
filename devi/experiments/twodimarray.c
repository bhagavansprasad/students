#include <stdio.h>
void twodimarr(int *arr, int i,int j);
main()
{
	int arr[2][3] = {
						{10,2,1},
						{20,3,4},
					};
	int i=2,j=3;
	twodimarr((int*)arr, i,j);
}

void twodimarr(int *arr, int i,int j)
{
	int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			printf("%d\n", *((arr+m*j)+n));
		}
	}
}
