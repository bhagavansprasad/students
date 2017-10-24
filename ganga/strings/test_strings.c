#include "stdio.h"

typedef struct test_strings_t
{
	int exp_result;
	int exp_len;
	int is_same;
	char buff[100];
	char buff2[100];
}test_strings;

test_strings strs[] = { 
	{3, 10, 1, "       how           rr           u", " how are you"},
	{3, 20, "how rrrrrrrr uu"},
	{0, 10, " "},
	{3, 20, "   dsfksjd kjkdsf kdshkk "}, 
	{1, 10, "a"},
	{6, 20, "a b c d e f"}
};

main()
{
	int wc = 0, i = 0;

#if 0
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
#endif
	for ( i = 0; i < sizeof(strs)/sizeof(test_strings); i++)
	{
		len = astrlen(strs[i].buff);

		if (len == strs[i].exp_len)
		{
			printf("SUCCES exp :%d, : wc :%d, for buff :%s\n", strs[i].exp_result, wc, strs[i].buff);
		}
		else
		{
			printf("FAILURE exp :%d, : wc :%d, for buff :%s\n", strs[i].exp_result, wc, strs[i].buff);
		}
	}


}

