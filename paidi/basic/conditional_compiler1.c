#include <stdio.h>
int main()
{
  #define COMPUTER "An amazing device"
  #ifdef COMPUTER
    printf(COMPUTER);
    printf("\n");
  #endif
}
