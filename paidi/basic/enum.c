#include <stdio.h> 
int main()
{
enum {WIN, TIE, BYE, LOSE, NO_SHOW} result;
enum {SUN, MON, TUE, WED, THU, FRI, SAT} days;

   result = WIN;

   printf("    WIN = %d\n",result);
   result = LOSE;

   printf("   LOSE = %d\n", result);
   result = TIE;

   printf("    TIE = %d\n", result);
   result = BYE;

   printf("    BYE = %d\n", result);
   result = NO_SHOW;

   printf("NO_SHOW = %d\n\n", result);

   for(days = SUN ; days <= SAT; days++)
      printf("The day code is %d\n", days);

   return 0;
} 
