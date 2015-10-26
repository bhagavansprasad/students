#include "stdio.h"
main()
{

int (*ptr)[4];

int arr[3][4]={1,2,3,4,5,6,7,8,9,10};

ptr=&arr[0];

++ptr;

printf("ptr[2]%d",((int *)ptr[2]));
ptr=(int*)[4],arr[0];

++ptr;

printf("%d",ptr[1][1]);

}

