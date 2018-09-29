#include <stdio.h>
int main()
{
	int a=0x12345678;
	int *p=&a;
	int sh1,sh2;

	*((short*)(&sh1)) = *((short*)p);
	*((short*)(&sh1)+1) = 0;
	printf("%x\n",sh1);

	*((short*)(&sh2)) = 0;
	*((short*)(&sh2)+1) = *((short*)p+1);
	printf("%x\n",sh2);
	return 0;
}
