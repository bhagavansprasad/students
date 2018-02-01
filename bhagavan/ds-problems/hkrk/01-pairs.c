#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int compare(const void *px, const void *py)
{
	int x = *((int*)px);
	int y = *((int*)py);

	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

int pairs(int k, int arr_size, int* arr) {
    // Complete this function
    int count = 0, i, j, diff = 0;

    for (i = 0; i < arr_size-1; i++)
		printf ("%d ", arr[i]);

	printf("\n");

	qsort(arr, arr_size, sizeof(int), compare);
    
    for (i = 0; i < arr_size-1; i++)
		printf ("%d ", arr[i]);
	printf("\n");

	i = 0; j = 1;
    for (i = 0; i < arr_size-1; )
    {
		diff = abs(arr[i] - arr[j]);
		printf ("%d %d %d\n", arr[i], arr[j], diff);
		if (diff == k)
		{
			count++;                  
			j++;
		}
		else if (diff > k)
			i++;
		else if (diff < k)
			j++;
    }
    
    return count;
}

int main() {
    int n = 5; 
    int k = 2;
	int arr[] = {1, 5, 3, 4, 2};


    int result = pairs(k, n, arr);
	printf ("result :%d\n", result);
}
