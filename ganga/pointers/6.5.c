#include <stdio.h>

main()
{
	int a = 0x12131415;
	short int *sp = &a;

	printf("--> before swap %x\n", a);

	int temp = *sp;
	*sp = *(sp+1);
	*(sp+1) = temp;

	printf("--> after  swap %x\n", a);
}
