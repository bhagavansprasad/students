#include<stdio.h>
main()
{
int a=626,c,b=626;
c=(c*10)+(a%10);
a=a/10;
c=(c*10)+(a%10);
a=a/10;
c=(c*10)+(a%10);
a=a/10;
if(b==c)
printf("the given is palindrome\n");
else
printf("not palindrome\n");
}
