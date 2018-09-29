#include "stdio.h"
#include "string.h"
void astrcpy(char *dest ,char *sourse);
main()
{
	char *name1= "mohansai" ;
	char *name2;
	//printf("hellow");
	astrcpy(name2,name1);
	printf("name1 %s\n\r",name1);
	printf("name2 %s\n\r",name2);
}

void astrcpy(char *dest ,char *sourse)
{
	while(*dest++=*sourse++);
	
}
