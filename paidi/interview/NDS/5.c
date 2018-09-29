#include <stdio.h>
int main()
{
 int c[] = {2,8,3,4,4,6,7,5};
 int j,*p = c, *q = c;
 for(j = 0; j < 5; j++)
 {
  printf("%d\r\n",*c);
  ++q;
 }
 for(j = 0;j<5;j++)
 {
  printf("%d\r\n",*p);
  ++p;
 }
}
