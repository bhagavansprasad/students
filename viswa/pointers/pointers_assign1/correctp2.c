#include <stdio.h>
main()
{
	int a=0x12345678,;
	short int sh1,sh2;
	sh1=*(((short*)&a)+0);
	sh2=*(((short*)&a)+1);
	printf("sh1:%x \t sh2:%x\n",sh1,sh2);	
}
