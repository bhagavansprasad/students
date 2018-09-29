#include <stdio.h>
main()
{
 int i = 0,j=0;
 if(i && j++)
 printf("1st%d...%d\n",i++,j);
 printf("2nd%d...%d\n",i,j);
}
