#include<stdio.h>
main()
{
	int a = 0x12131415,i;
	char *ch ;
	ch = (char*)&a;
	for(i = 3; i>=0; i--)
	{
		ch = ((char*)&a)+i;
		printf("------>%u\n",ch);
		printf("%x\n",*ch);
	}
	printf("\n");
}

