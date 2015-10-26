#include<stdio.h>
main()
{
   unsigned	int a=0x12131415;
   int i;
   char *p;
   p=&a;
   for(i=3;  i>=0;  i--)
   {
   	  printf("%x\n",*(p+i));
   }
}   

