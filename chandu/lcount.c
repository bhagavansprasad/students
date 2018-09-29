#include<stdio.h>
int get_linecount(char*p)
{ int i=0,count=0;
   for(i=0;p[i]!='\0';i++)
   {
     if(p[i]=='\n')
	 { count++;
	 }
   }
   return(count);
}
