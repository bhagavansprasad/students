#include <stdio.h>
main()
{
int n=10,y,fact;
int factorial(i);
y=factorial(i);
fact=y*factorial(i);
printf("%d",fact);
}
int factorial(int x)
{
 int fact=1;
 for(x=1;x<=n;x++)
 {
 fact*=x;
 }
 return fact;
} 
