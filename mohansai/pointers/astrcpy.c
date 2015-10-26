#include "stdio.h"
void astrcpy(char *dest ,char *sourse)
{
	char *t=dest;
	for( ; *sourse != '\0' ; )
	{
		*dest++=*sourse++;
	}	
	*dest++='\0';
	
//printf("dest%s",dest);
}
