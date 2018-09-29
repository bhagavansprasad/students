#include <stdio.h>

main()
{
	char str[10] = "addidaas";
	int i , j, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 65; j <= 97; j++)
		{
			if(str[i] == j)
			printf("%c %d\n", str[i], count++);
		}
	}
	printf("%d\n", count);
}
