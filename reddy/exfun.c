#include <stdio.h>
int main()
{
int a ;
int b ;
int c ;
int d ;

  printf ("Enter 4 nums to find factorials\n");
  scanf("%d %d %d %d", &a, &b ,&c, &d);
  printf("factor of( %d = %d, %d= %d, %d = %d, %d = %d\n", a, fact(a),b, fact(b),c, fact(c),d, fact(d));

}
int fact(int a)
{

   int p=1;
   int i=1;
   for(;i<=a; i++)
     p*=i;

  return p;
}
