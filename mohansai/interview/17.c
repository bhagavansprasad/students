#include<stdio.h>
void print(int *b)
{
  printf("%d", *b);
}

int main()
{
  int i=0;
  unsigned int *a = &i;
  print(a);
  return 0;
}

