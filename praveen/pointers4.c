#include <stdio.h>
main()
{
	int a=0x12131415;
	int i;
	char *cp;
	cp = (char *)&a;
	for(i=0;i<4;i++)
		printf("--->%d %x \n",i,*(cp+i));

	swap((cp+2),(cp+3));
	for(i=2;i<4;i++)
		printf("--->%d %x \n",i,*(cp+i));
	swap((cp),(cp+1));
	for(i=0;i<2;i++)
		printf("--->%d %x \n",i,*(cp+i));
}
