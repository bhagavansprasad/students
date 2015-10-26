#include <stdio.h>
int a = 10;
main()
{
int i ;
printf("address %u \n", &a);
for (i = 0; i<100 ;i++ )
printf(" %d \n", a);
}
