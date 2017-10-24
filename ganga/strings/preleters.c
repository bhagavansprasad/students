#include <stdio.h>

main()
{
	char str[10] = "hello";
	int i,j;
	for(j = 0; str[j] != '\0'; j++)
	{
			str[j] = str[++j];
	}
	printf("%s\n", str);
}
