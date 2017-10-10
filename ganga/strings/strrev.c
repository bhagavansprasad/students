#include <stdio.h>

main()
{
	char str[10] = "ramesh";
	char rev[10];
	int i, j = 0;
	char temp;

	for( i = 0; str[i] != '\0'; i++);
	printf("orginal  string is %s\n", str);

	for(j = 0; str[j] != '\0'; j++)
	{
		rev[j] = str[i-1];
		i--;
	}
	printf("reverse of a string is %s\n", rev);
}
