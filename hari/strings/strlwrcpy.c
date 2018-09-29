#include<stdio.h>
#include<string.h>
main()
{
 char s1[]="AURANET";
 char s2[100];
 int t;
 t=astrcpy(s2,s1);
 printf("%s",s1);
 printf("%s",s2);
 }
int astrcpy(char*d,char*s)
{
int i;
 for(i=0;s[i]!='\0';i++)
 {
  d[i]=atolower(s[i]);
  }
  return(i);
  }
  int atolower(int ch)
  {
  if (ch>=65 && ch <=90)
  {
  return(ch+32);
  }
   return ch;
   }

