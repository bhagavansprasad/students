#include<stdio.h>
#include<stdlib.h>
main()
{
   char s1[5]="subbu";
   char s2[5];
   int i=0;
   for(i=0;s1[i]!='\0';i++)

     {
        s2[i]=s1[i];
	
	}	
       s2[i]='\0';

   printf("%s\n",s2);
   
  
}


