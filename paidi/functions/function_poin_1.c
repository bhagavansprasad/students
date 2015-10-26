#include<stdio.h>
void my_function_point(int x)
{
  printf("%d\n",x);
}
int main()
{
  void (*foo) (int);
  foo = my_function_point;
  my_function_point(10);
  my_function_point(20);
  my_function_point(30);
  my_function_point(40);
  foo(100);
  foo(120);
  foo(130);
  foo(140);
}
