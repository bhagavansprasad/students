#include "stdio.h"

#if 0
	for (i = 0; sname[i] != '\0'; i++)
		printf ("%c ", sname[i]);

	printf ("\n");
	printf ("i :%d\n", i);
#endif

int astrlen(char *pname)
{
	int i = 0;

	for (i = 0; pname[i] != '\0'; i++);

	return i;
}

int get_capital_case_count(char *pname)
{
}

int get_small_case_count(char *pname)
{
}

//Return 0 if both are same
//Return 1 if they are not same
int string_compare(char *s1, char *s2)
{
}

int string_to_lower(char *s)
{
}

int string_to_upper(char *s)
{
}

int string_toggle_case(char *s)
{
}

main()
{
	char sname[100] = "Bhagavathi Tamilnadu";
	char s1[100] = "Bh";
	char s2[100] = "a";
	char s3[100] = "    ";
	char s4[100] = "";
	int len = 0;

	len = astrlen(sname);
	printf("The string '%s', length is :%d\n", sname, len);

	len = astrlen(s1);
	printf("'%s', length :%d\n", s1, len);

	printf("'%s', length :%d\n", s2, astrlen(s2));
	printf("'%s', length :%d\n", s3, astrlen(s3));
	printf("'%s', length :%d\n", s4, astrlen(s4));
}



