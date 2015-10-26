#include<stdio.h>
main()
{
int a[2][2]={{1,2},{3,4}};
int p,size,b;
p=&a+1;
b=a;
size=p-b;
printf("%u\n",p);
printf("%u",size);
}

