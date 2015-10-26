#include <stdio.h>
int astrlen(char* s2)
{
int i;
for(i=0;s2[i]!='\0';i++);
return (i);
}
