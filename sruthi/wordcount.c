#include<stdio.h>
int get_word_count(char *str)
{
  int j=0,i,count=0;
  while(str[j]==' ')
    j++;
  for(i=j;str[i]!='\0';i++)
  {
    while(str[i]!=' ')
	   i++;   
   if(str[i]!='\0')	
   {
      count=count+1;
	  //printf("%c",str[i-1]);
   }
   while(str[i]==' ')
	      i++;
    
  }
  return count;
}
