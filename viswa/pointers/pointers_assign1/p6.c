#include <stdio.h>
main()
{
	unsigned int a=0x15141312;
	int i,k=0;
	char *c;
	c=(char*)&a;
	for(i=0;i<=3;i++)
	{
		k++;
		printf("c %d :",k);
		printf("%x\n",*(c+i));
	}
}
