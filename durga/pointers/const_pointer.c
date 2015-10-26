#include <stdio.h>
main()
{
     int a = 23, b = 4;
   	 char* const  ch = "hai" ;
     int* const p =  &a; /*consent pointer to integer*/
	 printf("%d\n",*p);
	 *p = b;
	 printf("%d\n",*p);
	printf("%s\n",ch);
//	ch= "b";
//	printf("%s\n",ch);



}
