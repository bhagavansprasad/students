#include <stdio.h>
main()
{
  int a = 300;
  int *pa  = &a;
  char *pc = (char*)&a;
  printf("pa-->%d\n",*pa);
  printf("pc-->%d\n",*pc);
  printf("*(pa+1)-->%d\n",*(pa+1));
  printf("*(pc+1)-->%d\n",*(pc+1));
  printf("*(pc+2)-->%d\n",*(pc+2));
  printf("*(pc+3)-->%d\n",*(pc+3));
}
