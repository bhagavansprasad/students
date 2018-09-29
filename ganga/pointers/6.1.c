#include <stdio.h>

main()
{
	int i,a = 0x12131415;
	int *ip = &a;
	char *cp = &a;
	short int *sp = &a;

	printf("--->a :%x\n", *ip);
	
	printf(" :%x \n", *cp);
	for (i = 0 ; i < 3 ; i++)
	{
		cp++;
		printf(" :%x \n", *cp);
	}

	printf(" :%x \n", *sp);
	for (i = 0 ; i < 1 ; i++)
	{
		sp++;
		printf(" :%x \n", *sp);
	}
}

