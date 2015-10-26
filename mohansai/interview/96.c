#include<stdio.h>
int one_d[] = {1, 2, 3, 4, 5};
int main()
{
  int *ptr;
  ptr = one_d;
  ptr+=3;
  printf("%d %d", *ptr++, ++*ptr);
  return 0;
}
