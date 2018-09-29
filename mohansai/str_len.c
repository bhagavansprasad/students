#include"stdio.h"
#include"string.h"
int astrlen(char *name1);
main()
{
	int i;
	char name1[] = "Mohansai";

	i=astrlen(name1);

	printf("%d\n",i);
}

int astrlen(char *name1)
{

	int i;

	for(i=0;name1[i]!='\0';i++);
	return(i);
}


