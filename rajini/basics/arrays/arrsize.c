#include "stdio.h"
main()
{
int arr[5]={1,2,3,4,5};
int *p, q, *k;
p=&arr;
printf("arr---=%u\n",arr);
printf("*p---=%u\n",*p);
k=(&arr+1);
printf("*k------=%u\n",*k);
q= k-p;
printf("*q------=%d\n",q);
}


