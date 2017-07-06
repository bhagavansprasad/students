#include "stdio.h"

main()
{
	int i = 0;
	char sname[100] = "Bhagavathi Tamilnadu";

	printf ("Student Name :%s\n", sname);

	printf ("%c\n", sname[0]);
	printf ("%c\n", sname[1]);

	for (i = 0; sname[i] != '\0'; i++)
		printf ("%c ", sname[i]);

	printf ("\n");
	printf ("i :%d\n", i);
}
