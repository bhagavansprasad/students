#include "stdio.h"
main()
{
    static int i  = 10;
   {
      //int i = 20;
      {
        // int i = 30;
	 printf("%d\r\n",i);
      }
      printf("%d\r\n",i);
   }
   printf("%d\r\n",i);

}


