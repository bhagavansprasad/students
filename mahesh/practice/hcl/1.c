#include <stdio.h>
int fun(char *s)
   {
   	printf("%c\n",*s);
	return (*s?fun(s+1)+1:0);
   }

   void main()
   {
	int a = fun("orange");
   }

