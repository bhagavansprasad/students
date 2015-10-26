#include <stdio.h>
main()
{
 char i=257;
 int *iptr = &i;
// printf("address--->= %u\n",&i);
// printf("valu--->= %d\n",*iptr);
 printf("%d\t %d\t\n",*((char*) iptr),*((char *) iptr +1));
}
