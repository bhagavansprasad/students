#include "stdio.h"
main()
{
int arr[5]={5,6,7,8,9};
int *p=arr;
printf("arr----=%d\n",arr);
printf("p----=%d\n",p);
printf("*p-----=%d\n",*p);
printf("*arr----=%d\n",*arr);
printf("p+1-----=%d\n",p+1);
printf("arr+1-----=%d\n",arr+1);
printf("p[1]------=%d\n",p[1]);
printf("arr[1]----=%d\n",arr[1]);
printf("&arr-----=%d\n",&arr);
printf("*&arr------=%d\n",&arr);
printf("**&arr----=%d\n",**&arr);
printf("&arr+1-----=%d\n",&arr+1);
printf("&arr[1]-----=%d\n",&arr[1]);
printf("&arr[1]+1-----=i%d\n",&arr[1]+1);
}
