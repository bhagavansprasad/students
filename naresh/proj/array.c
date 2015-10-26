#include"stdio.h"
main()
{
int arr[5]={10,20,30};
int *p=arr;
printf("arr =%p\n",arr);
printf("p =%p\n",p);
printf("*p =%u\n",*p);
printf("*arr =%u\n",*arr);
printf("p+1 =%p\n",p+1);
printf("arr+1 =%p\n",arr+1);
printf("p[1] =%u\n",p[1]);
printf("arr[1] =%u\n",arr[1]);
printf("&arr =%p\n",*&arr);
printf("*&arr =%p\n",*&arr);
printf("**&arr =%u\n",**&arr);
printf("&arr+1 =%p\n",&arr+1);
}
