#include<stdio.h>
int main() 
{
  int xArray[] = { 1, 4, 8, 5, 1, 4 };
  int *ptr, yValue; 
  ptr  = xArray + 4;
  yValue = ptr - xArray;
  printf("%d",yValue);
  return 0;
}
