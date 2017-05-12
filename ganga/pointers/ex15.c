#include <stdio.h>
/*
   main()
   {
   int arr[] = { 0,1,2,3,4};
   int *ptr ;
   for( ptr = &arr[0]; ptr <= &arr[4]; ptr++)
   printf("%d\n", *ptr);
   }
 */
main()
{
	int arr[] = {0, 4, 3, 4};
	int i, *ptr;
	for(ptr = &arr[0], i = 0; i <= 4 ; i++)
		printf("%d\n", ptr[i]);
}
