#include<stdio.h>

int function2(int g,long int h)
{
  printf("--------g>%p\n",&g);
  printf("--------h>%p\n",&h);

  int i=60;
  int j=70;
//  printf("--------i>%u\n",i);
//  printf("--------i>%u\n",&i);
  function3(i,j);
}
