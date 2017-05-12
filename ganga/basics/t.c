#include "stdio.h"

typedef struct test_strings_t
{
	int exp_result;
	char buff[100];
}test_strings;

test_strings strs[] = { 
	{3, "       how           rr           u"},
	{3, "how rrrrrrrr uu"},
	{0, " "},
	{3, "   dsfksjd kjkdsf kdshkk "}, 
	{1, "a"},
	{6, "a b c d e f"}
};

main()
{
	int wc = 0, i = 0;

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

#if 0
int get_word_count(const char *s)
{
	int i=0,wc;
	if(s[i]==' ')
	wc=0;
	else
	wc=1;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ' && s[i+1]!=' '&& s[i+1]!='\0')
			wc++;
	}
	return wc;
}
#endif

