#include <stdio.h>
main()
{
int a,c=0;
printf("enter a value");
scanf("value=\t%d\n",&a);
c=((c*10)+(a%10));
a=a/10;
c=((c*10)+(a%10));
a=a/10;
c=((c*10)+(a%10));
a=a/10;
printf("%d\n",c);
}
