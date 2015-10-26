#include <stdio.h>
#include <string.h>
main()
{
	int l,i;
//        int strlen(char * p);
	char name[100] ="PRASAD REDDY";
         printf ("%s ", name); 
         l = astrlen(name);
	printf ("%d\n", l);
}

int astrlen(char * p)
{
	int i;
	for (i = 0;p[i] != '\0' ; i++);
	return (i);
}

