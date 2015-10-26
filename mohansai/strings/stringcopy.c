#include "stdio.h"
#include "string.h"

//char *strcpy(char *dest, const char *src);

main()
{
	char name1[10] = "mohansai";
	char name2[20] ;

	strcpy(name2,name1);
		
	printf("%s\n",name2);
}


