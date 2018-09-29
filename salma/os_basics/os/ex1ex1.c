#include<stdio.h>
main()
{
int *p=NULL;
p=0xbfbc4fa8;
printf("%d \n",*p);
*p=20;
printf("%d \n",*p);
}
