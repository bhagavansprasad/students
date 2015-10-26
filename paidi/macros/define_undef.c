#include<stdio.h>
#define TEMP 10

//#ifdef TEMP
  #undef TEMP
  #define MY 75
//#else
 // #define TEMP 100
//#endif

int main()
{
   //printf("%d\n",TEMP);
   printf("%d\n",MY);
return 0;
}
