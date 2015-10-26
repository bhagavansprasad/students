#include <stdio.h>

function3(int i,int j)
{
  int *pi=&i;
  int *pj=&j;
  printf("-----pi=%p\n",pi);
  printf("-----pj=%p\n",pj);
}

