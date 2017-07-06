#include "stdio.h"

main()
{
	int i = 0;
	char sname[100] = "Bhagavathi Tamilnadu";

#if 0
	for (i = 0;  ; i++)
	{
		if (sname[i] == '\0')
			break;
	}
#endif

#if 0
	for (i = 0; sname[i] != '\0'; i++)
		printf ("%c ", sname[i]);
#endif

#if 0
	for (i = 0; sname[i] != '\0' ; i++)
	{
	}
#endif

#if 0
	for (i = 0; sname[i] != '\0' ; i++);
#endif

	printf ("i :%d\n", i);
}
