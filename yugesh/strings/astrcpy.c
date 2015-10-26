#include <stdio.h>
#include "defs.h"
void astrcpy(char*s3, char*s1)
{
int i;
	for(i=0;s3[i]=s1[i];i++);
	s3[i]='\0';
}

