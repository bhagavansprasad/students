#include "stdio.h"
#include "string.h"
#pragma pack (1)

struct book
{
	int pages;
	char author;
	int edition;
	char type;
//	strcpy(author, "aura");
}; struct book b;

main()
{
	printf("%d\n",sizeof(b));
}

