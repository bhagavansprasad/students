#include <stdio.h>
extern int a = 10;/* its working*/
main()
{
 int a = 10;
 printf("val1--->= %d\n",a);
 my_function();
 my_function();
 my_function();
 my_function();
}

my_function()
{
 //extern int a=10;   /* its not working*/
// int a=10;        /*its working*/
 printf("val3--->= %d\n",a);
 a++;
}
