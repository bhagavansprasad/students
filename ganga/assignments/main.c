#define  32_ARCHITECTURE

#ifdef 32_ARCHITECTURE
    #define INT_SIZE 32
#else
    #define INT_SIZE 16
#endif
#include<stdio.h>
main()
{
 int i = 0;
 for(i = 1; i<= INT_SIZE; i++)
 {
  printf("-->%d\n", i);
 }
}
