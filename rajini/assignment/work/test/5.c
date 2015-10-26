#include <stdio.h>

int function3(int k,int l)
{
  printf("------k:%p\n",&k);
  printf("------l:%p\n",&l);
  
  int m=80;
  int n=90;
  printf("------m:%p\n",&m);
  printf("------m:%p\n",&n);
}
