#include<stdio.h>
main()
{
 /*
  * Define a list of aliases
  */
 enum months {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
 /*     A      A
          |      |
          |      |
   |      -------  list of aliases.
   --------------  Enumeration tag. */
 
 
 enum months month;  /* define 'month' variable of type 'months' */
 
 printf("%d\n", Sep); /* Assign integer value via an alias     
  * This will return a 9       */
}
