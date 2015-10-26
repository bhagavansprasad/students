#include <stdio.h>
#include <string.h>
void main()
{
  int i;
  char c;
  void *the_data;
  i = 7;
  c = 'a';

  the_data = &i;
  printf("pointer to integer valu--> %d\n",*(int*) the_data);

  the_data = &c;
  printf("points to the char--> %c\n",*(char*) the_data);

}
