#include <stdio.h>
int function1(int c,int d)
{
  printf("-------c:%p\n",&c);
  printf("-------d:%p\n",&d);
  
  int e=30;
  long int f=40;
  //printf("-------e:%u\n",&e);
//  printf("-------f:%lu\n",&f);

  function2(e,f);
}
