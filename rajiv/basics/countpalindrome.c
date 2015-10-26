#include <stdio.h>
#include <string.h>
int astrlen(char *str)
{
 int j=0;
 while(str[j]!='\0')
 {
  j++;
 } 
 return j;
} 
getpalindrome()
{
 int l=0,k=0;
 char str[100];
 int h=astrlen(str)-1;
 while(h>1)
 {
  if(str[l++]==str[h--])
  { 
   k++;
  } 
 } 
 printf("%d\n",k);
} 

