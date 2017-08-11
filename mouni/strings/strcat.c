#include "stdio.h"
main()
{
	char  s1[20]= "mounika";
	char  s2[10]= "chitla";
	int i, j;
	for(i=0;  s1[i]!='\0';  i++);

	for(j=0;  s2[j]!='\0';  j++)
	{
		s1[i]=s2[j];
		i++;
	}
	printf("%s\n",  s1);
}
