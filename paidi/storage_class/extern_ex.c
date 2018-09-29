#include <stdio.h>
int main()
{
  extern out;
  printf("%d\n",out);
  return 0;
}
int out = 100;

#if 0
// errore getting 
int main()
{
  printf("%d\n",out);
  return 0;
}
int out = 100;
#endif
