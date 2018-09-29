#include "stdio.h"
#include "string.h"

struct data_strings
{
	char string[100];
	int exp_res;
};

struct data_strings data[10] = {
	{ "welcome to aura", 3},
	{ "good  morning", 2},
	{ " have a  nice   day", 4},
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
		printf("-->%d.wcount :%d--%d.%s\n", i+1,data[i].exp_res, wc, data[i].string);

		//if (data[i].exp_res != wc)
		//	printf("-->%d.wcount :%d--%d.%s\n", i+1,data[i].exp_res, wc, data[i].string);
	}

return 0;
}

int get_word_count(char *st)
{
	int i, w = 0;

	for(i=0;st[i]!='\0';i++)
	{
		if(((st[i] != ' ') && ((st[i+1] ==' ')||(st[i+1]=='\0'))))
				w=w+1;
	}
				return w;
}


