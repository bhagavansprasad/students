#include<stdio.h>
#include<string.h>

main()
{
   char s1[4];
   char s2[25]="simha";

   
   int i=0,j=0;
  j=strlen(s2);
   printf("%d\n",j);
  for(i=0;s1[i]!='\0';i++)
   		{
		  s2[j+1]=s1[i];
		  j++;
		 }
    s2[j]='\0';	 
   printf("%s\n",s2); 
   
   }





