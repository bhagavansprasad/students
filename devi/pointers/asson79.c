#include <stdio.h>
main()
{

	int arr[5]= {10, 20, 30},i;
	char *ch =(char *) arr, *ch1 =(char *)&arr+1;
	int *ptr, *ptr1;
	printf( "size of int array arr = %d\n", sizeof(arr));
	for (i = 0; i <= 4 ; i++ )
	printf("arr[%d] = %d\n",i,arr[i]);
	printf("&arr+1 = %u\n", &arr+1);
	ptr = &arr+1;
	ptr1 = arr;
	printf("the size of array is ptr - arr = %d\n", (ptr-arr)*4);
	printf("the size of array is ptr-ptr1 = %d\n", (ptr -ptr1)*4);
	printf("the size of an array is ch1-ch = %d\n ", ch1-ch);
	//arr = arr++;
	//printf(" incrementing a i.e., arr++ = %u", arr);
}

