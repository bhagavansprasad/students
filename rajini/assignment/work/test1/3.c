#include <stdio.h>

int function2(int g, int h)
{
 int *pe=&g;
 int *pf=&h;
  printf("-------pe=%p\n",pe);
  printf("-------pf=%p\n",pf);
  int i=50,j=60;
   function3(i,j);
}   

