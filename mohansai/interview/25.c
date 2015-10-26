#include<stdio.h>
#include<string.h>

void main()
{ 
   char a[] = "String";
   char *b = "Strbing";   
   switch(strncmp(a,b,6>>1))
   {
       case 1: printf("No Match1");break;
       case 2: printf("No Match2");break;
       case 0: printf("Match");break;
       default: printf("Unknown");
   }   
}


