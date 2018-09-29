#include<stdio.h>
#include<string.h>
main()
{
char str1[20],str2[20];
printf("enter string");
gets(str1);
printf("enter string two");
gets(str2);


if( strcmp( str1, str2)==0)

printf("string is same");
else

printf("string is not same");
}
