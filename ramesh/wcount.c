#include "stdio.h"
#include "string.h"

struct data_strings
{
	char string[100];
	int exp_res;
};

struct data_strings data[10] = {
	{ "wel come to svcet", 4},
	{ "wel", 1},
	{ "wel a come", 3},
	{ " ", 0 },
	{ "  how    are    you     ", 3},
	{ "  a         ", 1},
	{ "           ", 0},
	{ "   a   b         ", 2},
	{ "dddddddddddddd", 1},
 	{ "a", 1}
};

main()
{
	int wc = 0;
	int i = 0;

	for (i = 0; i <= 9; i++)
	{
		wc = get_word_count(data[i].string);	
		//printf("-->%d.wcount :%d--%d.%s\n", i+1,data[i].exp_res, wc, data[i].string);

		if (data[i].exp_res != wc)
			printf("-->%d.wcount :%d--%d.%s\n", i+1,data[i].exp_res, wc, data[i].string);
	}

	return 0;

#if 0
	wc = get_word_count(a1);	
	printf("-->wc :%d\n", wc);

	wc = get_word_count(a2);	
	printf("-->wc :%d\n", wc);

	wc = get_word_count(a3);	
	printf("-->wc :%d\n", wc);

	wc = get_word_count(a4);	
	printf("-->wc :%d\n", wc);

	wc = get_word_count(a5);	
	printf("-->wc :%d\n", wc);
#endif
}

int get_word_count(char *pb)
{
	int i, w = 0;

	for(i=0;pb[i]!='\0';i++)
	{
		if(((pb[i] != ' ') && (pb[i+1] ==' '))||pb[i+1]=='\0')
			w=w+1;
	}
	return w;
}

