#include <stdio.h>
#include<string.h>
char *astrchr(char *str1,char n)
{
while(*str1!=n)
{
	str1++;
}
return str1;
}
main()
{
char str1[]="salmamateen";
char *ptr;
char c = 'm';
ptr=astrchr(str1,c);
printf("%s\n",ptr);
}
