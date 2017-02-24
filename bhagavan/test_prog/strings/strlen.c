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
int astrcmp(char *s1, char *s2)
{
}

int astrtolower(char *s)
{
}

int astrtoupper(char *s)
{
}

int string_toggle_case(char *s)
{
}

//1 Yes
//0 No
int is_lower(char ch)
{
	//......
}

//1 Yes
//0 No
int is_upper(char ch)
{
	//......
}

main()
{
	char sname[100] = "Bhagavathi Tamilnadu";
	char s1[100] = "How are you";
	char s2[100] = "How are you";
	char s3[100] = "How and are you";
	char s4[100] = "";
	int len = 0;
	char ch1 = 'x'
	char ch2 = 'x'

	len = astrlen(sname);
	printf("The string '%s', length is :%d\n", sname, len);

	len = astrlen(s1);
	printf("'%s', length :%d\n", s1, len);

	printf("'%s', length :%d\n", s2, astrlen(s2));
	printf("'%s', length :%d\n", s3, astrlen(s3));
	printf("'%s', length :%d\n", s4, astrlen(s4));

	if (is_lower(ch1) == 1)
		printf("%c is a lower\n");
	else
		printf("%c is a UPPER\n");

	if (is_upper(ch2) == 1)
		printf("%c is a UPPER\n");
	else
		printf("%c is a lower\n");

	if (is_lower(ch2) == 1)
		printf("%c is a lower\n");
	else
		printf("%c is a UPPER\n");

	if (is_upper(ch1) == 1)
		printf("%c is a UPPER\n");
	else
		printf("%c is a lower\n");

	// xxxxx has 2 capital letters and 18 small letters
	printf("%s : capital count %d and %d small letters", sname, get_capital_case_count(sname), get_small_case_count(sname));

	printf("Before astrtoupper sname :%s", sname); //Bhagavathi
	astrtoupper(sname);
	printf("After  astrtoupper sname :%s", sname); //BHAGAVATHI

	printf("Before astrtosentencecase sname :%s", sname); //BHAGAVATHI //bhagavathi //bHaGaVatHi
	astrtosentencecase(sname);
	printf("After  astrtosentencecase sname :%s", sname); //Bhagavathi

	printf("Before astrtolower sname :%s", sname); //Bhagavathi
	astrtoupper(sname);
	printf("After  astrtolower sname :%s", sname); //bhagavathi

	retval = astrcmp(s1, s2)  // SAME
	if (retval == 0)
		printf("%s and %s are SAME\n", s1, s2);
	else
		printf("%s and %s are NOT SAME\n", s1, s2);

	retval = astrcmp(s2, s1)  // SAME
	if (retval == 0)
		printf("%s and %s are SAME\n", s2, s1);
	else
		printf("%s and %s are NOT SAME\n", s2, s1);

	retval = astrcmp(s2, s3)  // NOT SAME
	if (retval == 0)
		printf("%s and %s are SAME\n", s2, s3);
	else
		printf("%s and %s are NOT SAME\n", s2, s3);

	retval = astrcmp(s1, s3)  // NOT SAME
	if (retval == 0)
		printf("%s and %s are SAME\n", s1, s3);
	else
		printf("%s and %s are NOT SAME\n", s1, s3);
}



