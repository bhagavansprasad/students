#include<stdio.h>
main()
{
 int bs=1780;
 int dap=28;
 int hrap=43;
 int da,hra,gs;

 da=(bs*dap/100);
 hra=((bs*hrap)/100);
 gs=(bs+da+hra);
 {
   printf("%d\n",da);
   printf("%d\n",hra);
   printf("%d\n",gs);
 }

}
