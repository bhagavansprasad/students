#include <stdio.h>
main()
{
int n=0, i,a=1;
 printf(" Enter the n value\t :");
 scanf("%d", &n);
 for(i=n;i>=1;i--)
 {
    printf("%d *", i);
     a=a*i;
  }
 printf("\n\n Factorial of %d is :%d \n\n",n,a);
}
    

