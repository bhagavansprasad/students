#include "stdio.h"
main()
{
int arr[5]={5,6,7,8,9};
int *p,*k,*r;
p=(int *)arr;
k=(int *)(&arr+1);
r=(int *)(k-p);
printf("%p,%p,%d\n",k,p(int)r);
}
