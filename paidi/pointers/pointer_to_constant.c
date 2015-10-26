#include <stdio.h>
main()
{
 int var1 =20,var2 =10;
 const int *ptr = &var1;
 printf("*ptr1-->= %d\n",*ptr);
            ptr = &var2;
 printf("*ptr2-->= %d\n",*ptr);
}
