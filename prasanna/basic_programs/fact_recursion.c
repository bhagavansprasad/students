#include<stdio.h>
int fact(int );

int main()
{
  int n;
  printf("enter the fact of number\n");
  scanf("%d",&n);
  printf("Factorial of %d is : %d\n",n,fact(n));
  return 0;
}

int fact(int n)
{
  if(n==0)
  return 1;

  return n*fact(n-1);
}
