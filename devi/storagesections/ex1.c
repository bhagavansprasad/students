#include<stdio.h>
void displayBits(int x);
main()
{
int a,b;
printf("enter a and b values in hexadecimal:");
scanf("%x %x",&a,&b);
printf("a=%X\n",a);
displayBits(a);
printf("b=%X\n",b);
}
