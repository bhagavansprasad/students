#include<stdio.h>

int get_ns_count(char *ptr, char ch)
{
	int i,nc=0;

	for(i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] == ch)
			nc=nc++;
	}

	return (nc);
}

main()
{
	char name[]="a baby born";
	char needle = 'b';
	int count = 0;

	count = get_ns_count(name, needle);

	printf("total num of %c is:%d\n", needle, count);
}


