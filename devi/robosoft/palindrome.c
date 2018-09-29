#include<stdio.h>
#include <string.h>
int stpal(char str1[50], char str2[50]);
void main()
{
char str[50], rev[50];
int pal;
printf("\n\n\t ENTER A STRING…: ");
gets(str);
pal = stpal(str, rev);
printf("\n\t THE REVERSED STRING IS…: ");
puts(rev);
if(pal)
printf("\n\t THE ENTERED STRING IS A PALINDROME");
else
printf("\n\t THE ENTERED STRING IS NOT A PALINDROME");
}


int stpal(char str1[50], char str2[50])
{
int i = 0, len = 0, r = 0, pal = 1;
while(str1[len]!='\0')
len++;
for(i=len-1; i>=0; i--)
{
str2[r] = str1[i];
r++;
}
str2[r] = '\0';
for(i=0; i<=len-1; i++)
{
if(str1[i]==str2[i])
pal = 1;
else
{
pal = 0;
break;
}
}
return pal;
}
