#include <stdio.h>
int main()
{

	int a=0x12345678;
	int *p=&a;
	int a4;
	
	*((char*)(&a4)+3) = *((char*)p+3);
	*((char*)(&a4)) = 0;
	*((char*)(&a4)+1) = 0;
	*((char*)(&a4)+2) = 0;
	printf("%x\n",a4);
	return 0;

}






/*

   int a=0x12345678;
   int *p=&a;
   int sh1,sh2;

   sh1 = *(short*)p;
   printf("%x\n",sh1);
   sh2 = *((short*)p+1);
   printf("%x\n",sh2);
   return 0;
   }

 */







/*
   int a=0x12345678;
   int *p=&a;
   int a1,a2,a3,a4;

   a1=(*(char*)p);
   printf("%x\n",a1);
   a2=*((char*)p+1);
   printf("%x\n",a2);
   a3=*((char*)p+2);
   printf("%x\n",a3);
   a4=*((char*)p+3);
   printf("%x\n",a4);
   return 0;

   }

 */







/*
   int a=0x12345678;
   int *p=&a;
 *(char*)p=10;
 printf("%x\n",a);
 *(short*)p=10;
 printf("%x\n",a);
 *(int*)p=10;
 printf("%x\n",a);
 return 0;
 }*/

