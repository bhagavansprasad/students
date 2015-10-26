#include<stdio.h>
main()
{
int a=7;
int *b,*c;
b=&a;
c=b;
printf("%u\t %u\t %u\n",&a,b,c);
printf("%d\t%d\t%d\t%d\n",a,*(&a),*b,*c);
}
