#include<stdio.h>
main()
{
int a=10;
int *p=&a;
printf("%u %u %u %u %u\n",++p,p,p++,p--,--p);
printf("%d %d %d %d %d %d %d",++a, a, --a,a,a++,a--,++a);
//printf("%u %u ",&a,&a+1);
}

