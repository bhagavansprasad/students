#include <stdio.h>
main()
{
	char str[]="hai";
	char str1[]="Hai";
	if(strcasecmp(str,str1)==0)
	printf("\nEqual\n");
	else
	printf("not Equal\n");
}
