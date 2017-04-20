#include <stdio.h>

main()
{
	int i,a = 0x12131415;
	char *cp = &a;
	/*printf("--> ch1 :%x\n", *cp);
	  printf("--> ch2 :%x\n", *(cp+1));
	  printf("--> ch2 :%x\n", *(cp+2));
	  printf("--> ch2 :%x\n", *(cp+3));
	 */
	for (i = 0; i <= 3; i++)
	{
		printf("%c\n", *cp);
		cp++;
	}
}
