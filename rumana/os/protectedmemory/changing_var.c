#include<stdio.h>
main()
{
int *p=NULL;
p=0x7fff4b1ee148;
*p=20;
printf("value at this address is %d\n",*p);
printf("address of p is %p\n",p);
}
