#include<stdio.h>
main()
{
	int a=0x12131415;
	printf("%x\n",a);
	int b=*((short *)&a);
	*((short *)&a)=*((short *)&a+1);
	*((short *)&a+1)=b;
	printf("%x\n",a);

}
