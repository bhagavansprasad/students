#include <stdio.h>

int add(int p,int q)
{
  int c;
  return c = p+q;
}

int mul(int p,int q)
{
  int c;
  return c = p*q;
}
int div(int p,int q)
{
  int c;
  return c = p/q;
}
int sub(int p,int q)
{
  int c;
  return c = p-q;
}
int main()
{
  int retval = 0;
  retval = add(10,20);
  printf("add -->= %d\n",retval);

  retval =mul(20,30);
  printf("mul -->= %d\n",retval);

  retval =div(40,10);
  printf("div -->= %d\n",retval);

  retval =sub(50,40);
  printf("sub -->= %d\n",retval);

}
