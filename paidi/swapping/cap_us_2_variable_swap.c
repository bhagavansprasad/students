#include <stdio.h>
main()
{
 int a=10,b=30;
 a = a^b;
 b = a^b;
 a = a^b;
 printf("%d\n",a);
}
