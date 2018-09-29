#include <stdio.h>
main()
{
char i;
int s;
s=(char *)(&i+1)-(char *)(&i);
printf("%d\n",s);
}
