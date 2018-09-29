#include<stdio.h>

main()
{
	int a=0x12131415;
	char *cp=(char *)&a;
	printf("%x",*cp);
	cp++;
	printf("%x",*cp);
	short *sp=(short *)&a;
	*sp= :0;
	printf("%x",*sp);
}

