#include <stdio.h>
main()
{
 if(fork()>0)
 {
  printf("parent\n");
  sleep(50);
 }
}
