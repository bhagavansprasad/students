#include <stdio.h>

main(int argc, char * argv[])

{

int i;

i= aatoi(argv);

printf(" entered string is %d",i);


}



int aatoi(char *p)
{
  int i,j;

  i=0;
  j=1;
  while(('-' == (*p)) || ((*p) == '+'))
    {
      if (*p == '-')
        j = j * -1;
      p++;
    }
  while ((*p>= '0') && (*p <= '9'))
    {
      i = (i * 10) + ((*p) -'0');
      p++;
    }
  return (i * j);
}
