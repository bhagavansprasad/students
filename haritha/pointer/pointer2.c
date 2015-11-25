#include <stdio.h>
main()
{
	int a=0x12131415,k=0,i;
	//for(i=0;i<=1;i++)
	//{
	//printf("%x",k);
	//}
	short *sp=(short*)&a;
	*sp=00;
	printf("%04x",*sp);
	char *cp=(char*)&a;

	for(i=2;i<=3;i++)
	{
		printf("%x\n",*(cp+i));
	}
}
