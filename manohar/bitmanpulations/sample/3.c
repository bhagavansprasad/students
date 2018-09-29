#include <stdio.h>
int main()
{

	int a=0x12345678;
	int *p=&a;
	int a1,a2,a3,a4;
	
	*((char*)(&a1)) = *((char*)p);
	*((char*)(&a1)+1) = 0;
	*((char*)(&a1)+2) = 0;
	*((char*)(&a1)+3) = 0;
	printf("%x\n",a1);
	*((char*)(&a2)) = 0;
	*((char*)(&a2)+1) =*((char*)p+1);
	*((char*)(&a2)+2) = 0;
	*((char*)(&a2)+3) = 0;
	printf("%x\n",a2);
	*((char*)(&a3)) = 0;
	*((char*)(&a3)+1) = 0;
	*((char*)(&a3)+2) = *((char*)p+2);
	*((char*)(&a3)+3) = 0;
	printf("%x\n",a3);
	*((char*)(&a4)) = 0;
	*((char*)(&a4)+1) = 0;
	*((char*)(&a4)+2) = 0;
	*((char*)(&a4)+3) = *((char*)p+3);
	printf("%x\n",a4);

	return 0;

}




