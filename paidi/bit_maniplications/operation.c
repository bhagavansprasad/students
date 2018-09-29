#include <stdio.h>
main()
{
 int x = 2;
 printf("xvalu--->= %d\n",x);
 x = (x<<x<<x) | (x<<x<<x) | x<<!!x | !!x;
 printf("second x valu--->= %d\n",x);
}
