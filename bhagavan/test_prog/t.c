#include "stdio.h"

char b1[100] = "Hello how are you.  I am";

#if 0
char buffs[10][100] =  {
	{"       how           rr           u"},
	{"how rrrrrrrr uu"},
	{"how rrrrrrrr uu"},
	{" "},
	{"dsfksjd kjkdsf kdshkk "}, 
	{"a"},
	{"a b c d e f"},
	{"a b c d e f"},
	{"a b c d e f"},
	{"a b c d e f"}
 };
#endif

typedef struct test_strings_t
{
	int exp_result;
	char buff[100];
}test_strings;

test_strings strs[] = { 
	{3, "       how           rr           u"},
	{3, "how rrrrrrrr uu"},
	{0, " "},
	{3, "dsfksjd kjkdsf kdshkk "}, 
	{1, "a"},
	{7, "a b c d e f"}
};


main()
{
	int wc = 0, i = 0;

#if 0
	wc = get_word_count(b1);
	printf("wc :%d, for buff :%s\n", wc, b1);

	wc = get_word_count(b2);
	printf("wc :%d, for buff :%s\n", wc, b2);

	for ( i = 0; i < 10; i++)
	{
		wc = get_word_count(buffs[i]);
		printf("wc :%d, for buff :%s\n", wc, buffs[i]);
	}
#endif

	for ( i = 0; i < sizeof(strs)/sizeof(test_strings); i++)
	{
		wc = get_word_count(strs[i].buff);

		if (wc == strs[i].exp_result)
		{
			printf("SUCCES exp :%d, : wc :%d, for buff :%s\n", strs[i].exp_result, wc, strs[i].buff);
		}
		else
		{
			printf("FAILURE exp :%d, : wc :%d, for buff :%s\n", strs[i].exp_result, wc, strs[i].buff);
		}
	}

}

int get_word_count(const char *s)
{
	//....

	return 0;
}


int astrncmp(const char *s1, const char *s2)
{
}










