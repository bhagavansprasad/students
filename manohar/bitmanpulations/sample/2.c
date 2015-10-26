#include <stdio.h>
main()
{
  int a=0x12345678;
   int *p=&a;
   int sh1,sh2;

   sh1 = *(short*)p;
   printf("%x\n",sh1);
   sh2 = *((short*)p+1);
   printf("%x\n",sh2);
   return 0;
  

}
