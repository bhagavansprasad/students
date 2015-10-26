#include <stdio.h>
#include <string.h>
main()
{
	char str1[10]="SDM";
	char str2[10]="sam";
//	int val;
//	val = strcmp(str1,str2);
	printf("%d\n",strcmp(str1,str2));

	printf("%d\n",strcasecmp(str1,str2));
}
