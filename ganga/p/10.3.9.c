#include <stdio.h>
struct e
{
  int a;
};
union s
{
 char b;
 char f;
};
 
int main( ) {
struct e c;
union s d;
c.a=300;
d.b=c.a;
   printf( "c.a : %d\n",c.a);
   printf("d.b=%d\n",d.b);
   d.f=c.a;
   printf("d.f=%d\n",d.f);





   return 0;
}
