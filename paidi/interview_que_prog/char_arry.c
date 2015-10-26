#include<stdio.h>
main()
{
char x[] = "abcde";
char e[] = "ptcde";
char *y= "abcde1234";
char *r= "ABCD1234";
char *d= "1234";
printf("%c \n", x[3]);
printf("%s \n", e);
printf("%c \n", y[3]);
printf("%s \n", x);
printf("%s \n", y);
printf("%s \n", r);
printf("%s \n", d);
}
