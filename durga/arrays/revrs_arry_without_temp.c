#include <stdio.h>
#include <string.h>
main()
{
	char arr[10] = "prasad";
	int i;
	int n = strlen(arr);
	for( i = 0; i<n/2; i++)
	{
	  arr[i] = arr[i] - arr[n -1-i];
	  arr[n - 1 - i] =   arr[i]+arr[n - 1-i];
	  arr[i] = arr[n - 1 - i] - arr[i];

	}
	for( i = 0 ; i < n; i++)
	printf("%c\t", arr[i]);
}
