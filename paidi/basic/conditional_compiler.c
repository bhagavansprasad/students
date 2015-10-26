#include <stdio.h>
#define paidi 0      
main()
{
    #ifdef paidi
      printf("hello\n");      //this is compiled as  x is defined
   #else
      printf("bye\n");       //this is not compiled 
   #endif
}
