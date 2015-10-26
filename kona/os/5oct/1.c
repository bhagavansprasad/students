#include <stdio.h>
//# dumpe2fs /dev/sdb3 | grep -i 'Block size';
main()
{
	int i,a=10;
	printf("--->the address of a is %p\n",&a);
	for(i=0;i<100;i++)
	{
		printf("---the value of a is %d\n",a);
	}
}
