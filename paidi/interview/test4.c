#include <stdio.h>
int main()
{
  unsigned char c =126;
  c=c++;
  if(c=='a')
  c--;
  else
  c++;
  printf("valu--->= %d\n",c);
}
