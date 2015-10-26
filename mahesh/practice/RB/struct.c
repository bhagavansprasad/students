#include <stdio.h>
typedef struct book
{
	int value;
	char name;
}aa;
main()
{
	aa.book.value=5;
	printf("--%d\n",aa.value);
}

