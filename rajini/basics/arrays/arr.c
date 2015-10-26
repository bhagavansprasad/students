#include "stdio.h"
main()
{
int arr[5]={5,6,7,8,9};
int *p=arr;
printf("arr----=%p\n",arr);
printf("p-------=%p\n",p);
printf("*p------=%d\n",*p);
printf("*arr----=%d\n",*arr);
printf("p+1-----=%p\n",p+1);
printf("arr+1---=%p\n",arr+1);
printf("p[1]-----=%d\n",p[1]);
printf("arr[1]-----%d\n",arr[1]);
printf("&arr-------%p\n",&arr);
printf("*&arr------%p\n",*&arr);
printf("&arr+1-----%p\n",&arr+1);
}
