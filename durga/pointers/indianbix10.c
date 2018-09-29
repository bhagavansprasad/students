#include <stdio.h>
main()
{
int a[2][3][3]={1,2,3,4,5,6,7,8,9,10,12,11,21,32,12};
printf("%u\t %u \t %u\t %u\n",a,*a,**a,***a);

}
