#include"string.h"
#include "stdio.h"

int astr_case_cmp(char *s1 ,char *s2)
{
	int i = 0;	

	while(1)
	{
		if (tolower(s1[i]) != tolower(s2[i]))
		{
			return -1;
		}
	}
	return 0;
}

main()
{
	char name[10]  = "MOHANSAI";
	char name1[10] = "moaansai";
	int  retval;

	printf("Before ...\n");
	printf("s1 :%s\n", name);
	printf("s2 :%s\n", name1);

	///retval = astr_case_cmp( name,name1);
	retval = strcasecmp(name, name1);
	printf("After ...retval :%d\n", retval);
	printf("s1 :%s\n", name);
	printf("s2 :%s\n", name1);
}


