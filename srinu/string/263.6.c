#include <stdio.h>
#include <string.h>
main()
{
char str[]="vijayanagar";
fun(str);
}
void fun(char str[])
{
int i;
for(i=5;i<strlen(str);i++)
printf("%c\n",str[i]);
}
