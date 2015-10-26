#include<stdio.h>
main()
{
int arr[5]={10,20,30};
int *p=(int *)arr;
int *k;
k=(int *)(&arr+1);
int *q;
q=(k-p);
printf("size is array = %d\n",q);
}
