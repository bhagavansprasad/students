#include <stdio.h>
/* main()
{
 int a=20,b;
 b= fun(20);
 printf("%d\n",b);

}
int fun(int x)
{
 return (x >20 ?20 : 10 );
 }
 */

 main()
 {
  int a,b,c,number;
  printf("enter the number");
  scanf("%d",&number);
  while(number!= 0)
  {
   a = number%10;
   b = number/10;
   printf("%d",a);
   number=b;
   }

 }

