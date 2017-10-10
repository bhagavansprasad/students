#include "stdio.h"
#include "string.h"
#pragma pack (2)

struct book
{
	char type;
	char author;
	int pages;
	int edition;
//	strcpy(author, "aura");
};

main()
{
	//printf("%ld\n",sizeof(b));
	printf("%ld\n",sizeof(struct book));
}

