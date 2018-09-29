#include<stdio.h>
main()
{
int a[5]={1,2,3,4,5};
int p=&a+1;
int q=a;
int r=int(p)-int(q);
printf("size of:%u\n",p);
printf("size of :%u\n",q);
printf("size of :%u\n",r);
}

