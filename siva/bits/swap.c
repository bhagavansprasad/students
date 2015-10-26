#include<stdio.h>
main()
{
int  i=10,k=20;
printf("i=%d\t k=%d\n",i,k);
i=i^k;
k=i^k;
i=i^k;
printf("i=%d\t k=%d\n",i,k);
}
