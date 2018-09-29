#include<stdio.h>
int astrlen(char *);
main()
{
char str[]="SalmaMateen";
int t;
t= astrlen(str);
printf("length is: %d\n",t);
}
int astrlen(char p[])
{
  int i;
  for(i=0;p[i]!='\0';i++);
  return i;
}
