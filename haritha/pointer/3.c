#include <stdio.h>
main()
{
int a=0x12131415;
char *cp=&a;
printf("%x",*cp);
cp++;
//printf("%x",*sp);
*cp=0;
printf ("%x",*cp);
}

