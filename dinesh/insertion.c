# include <stdio.h>
main ()
{
	int i,j,k,n=5;
	int arr[5] = {65,25,46,98,12};
	for(i = 1;i < n;i++)
	{
		k = arr[i];
		for (j = i-1; k < arr[j] && j>=0; j--)
		{
				arr[j+1] = arr[j];
				k = arr[j+1];
		}
	}
	printf("sorted list");
	for (i = 0;i < n;i++)
		printf("%4d",arr[i]);
}
