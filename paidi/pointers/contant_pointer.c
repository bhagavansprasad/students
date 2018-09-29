#include <stdio.h>
main()
{
 int var1 = 4;
 int *const ptr = &var1;
              //ptr = &var2;//not working
			   //ptr = 10;//not working
			   *ptr = 10;//it'sworking
 printf("*ptr-->=%d\n",*ptr);
 printf("var1-->= %d\n",var1);


}
