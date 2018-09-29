#include <stdio.h>
main()
{
int a = 2,b = 4;
const char* ch = "a";
const int *p;     /* pointer to the conest integer*/
p = &a;
printf("%d\n",*p);
*p = 7;
printf("%d\n",*p);
printf("%c\n",*ch);
ch = "b";
printf("%c\n",*ch);
}
