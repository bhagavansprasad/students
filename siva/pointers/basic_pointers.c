#include<stdio.h>
main()
{
int a=10;
int *p;
p=&a;
printf("PTR ADDRESS=%u\t PTR VALUE=%d\n",&p,p);
printf("I VALUE=%d\t PTR VALUE AT THAT POINTER=%d\n",a,*p);
*p=20;
printf("AFTER ASSIGNING %d",*p);
}

