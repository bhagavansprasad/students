/* with out using or operation*/

#include <stdio.h>
#define bit(x,y) ~((~x) & (~y))
main()
{
int a,b;
a=5;
b=6;
printf("%d\n",bit(a,b));
}
