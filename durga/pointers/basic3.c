#include<stdio.h>
main()
{
  int a = 0x12131415,i;
  short int *sh1, *sh2;
  char *p;
  sh2 = (short int*)&a;
  sh1 = (short int*)&a+1;
  for(i = 0, p = sh2; i<2; i++,p++)
  {
   //printf("------>%u\t",p);
   printf("%x\t",*p);
   }
   printf("\n");
   for( i = 0,p = sh1; i<2; i++,p++)
   {
    //  printf("----->%u\t",p);
	  printf("%x\t",*p);
	}
	}


