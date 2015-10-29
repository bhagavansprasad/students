#include<stdio.h>
#include <string.h>
int stcpy(char *str1, char *str2);
int main()
{
char *str1="devi", *str2;
printf("%s\n",str1);
printf("%c\n",*str1);
stcpy(str1,str2);
printf("\n\t THE COPIED STRING IS…: ");
printf("%s\n",str2);
return 0;
}
int stcpy(char *str1, char *str2)
{
while((*str2 = *str1)!='\0')
{
str2++;
str1++;
}
}
