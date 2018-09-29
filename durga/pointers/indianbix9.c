#include <stdio.h>
main()
{

	char *str = "peace";
	char *s = str;
	printf("%s\n", s++ + 3);
	printf("%s\n", s);
}
