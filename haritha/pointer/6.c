#include <stdio.h>
main()
{
	int a=0x12131415,i;
	short *sp=(short*)&a;
	sp++;
	printf("%x",*sp);
	char *cp=(char *)&a;
	printf("%x",*cp);
	cp++;
	printf("%x",*cp);
}






