#include <stdio.h>
#include <string.h>
int getpalindrome(char *str1);
int getword(char *str,char *str1);
/*int strlen(char str)
{
 int j=0;
 while(str[j]!='\0')
 {
  j++;
 } 
 return j;
} */

main()
{
 int count=0;
 char str[]="dad madam punished me mom ";
 char str1[100];
 printf("string is %s\n",str);
 count=getword(str,str1);
 printf("no. of palindromes in the string are %d\n",count);
} 

int getword(char *str,char *str1)
{
 int i=0,k=0,c=0;
 while(str[i]!='\0')
 {
  if(str1[i]=' ')
  { 
   str1[c]=str[i];
   c++;
  }
  i++;
 } 
k=getpalindrome(str1);
  return k;
}  

