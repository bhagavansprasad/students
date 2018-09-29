#include <stdio.h>
main()
{
	int arr[5];
	printf("%u\t%u\t%u\t%u\t%u\n",arr,&arr+0,&arr,&arr+1,arr+1);
}
