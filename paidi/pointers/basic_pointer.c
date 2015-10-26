#include <stdio.h>
main()
{
  int *ptr=10;
  printf("int-->ptr=%d\n",sizeof(ptr));
  printf("int-->*ptr%d\n",sizeof(*ptr));
  char *p=10;
  printf("char-->ptr=%d\n",sizeof(p));
  printf("char-->*ptr%d\n",sizeof(*p));
}
