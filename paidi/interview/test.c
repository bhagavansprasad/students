#include <stdio.h>
int fun(int);
int main()
{
 int i=012;
 int res;
 res= fun(i);
 printf("the valu i--> = %d\n",i);
 return 0;

}

int fun(int s)
{
  s=s++;
  return (s);
}
