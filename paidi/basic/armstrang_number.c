#include <stdio.h>
int main()
{
   int r;
   long number =1000, c, sum = 0, temp; 
   for( c = 1 ; c <= number ; c++ )
   {
      temp = c;
      while( temp != 0 )
      {
         r = temp%10;
         sum = sum + r*r*r;
         temp = temp/10;
      }
      if ( c == sum )
         printf("%ld\n", c);
      sum = 0;
   }
 
   return 0;
}
