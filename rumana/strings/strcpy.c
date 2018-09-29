#include<stdio.h>
#include<string.h>
main()
{
char s1[20],s2[20];
//printf("enter s1");
//gets(s1);
printf("enter s2");
gets(s2);
strcpy(s1,s2);
printf("string 1 :%s\n",s1);
printf("string 2 : %s\n",s2);
}
