#include <stdio.h>

main()
{
	char str[10] = "ramesh";
	int i, j = 0;
	char temp;

	for( i = 0; str[i] != '\0'; i++);

	for( j = 0; str[j] != '\0'; j++);
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		printf("%c", str[j]);
	}
	printf("\n");
		printf("%s\n", str);
}
