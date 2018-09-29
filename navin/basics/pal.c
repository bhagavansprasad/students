#include <stdio.h>
main()
{

int a=521;
int b,c=0,d,e,f;

b=a/10;f=b/10;
d=b%10;
c=((c*10)+(a%10));
e=((c*100)+(d*10)+f);
if (a==e)
printf("Yes , because reverse of  %d is also %d",a,e);
else
printf ("\n not polindrome\n");
}

