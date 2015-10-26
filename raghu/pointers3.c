#include <stdio.h>
main()
{
	int a = 0x12131415;
	char *cp;
	int i;
	cp = (char *) &a;
	printf("--->0 %x\n",*(cp+1));
	printf("--->1 %x\n",*(cp+0));
	printf("--->2 %x\n",*(cp+3));
	printf("--->3 %x\n",*(cp+2));
	/*for(i = 0; i < 4;i++)
	printf("--->%d %x\n",i,*(cp+i));*/


}
