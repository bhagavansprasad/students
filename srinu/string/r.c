#include "stdio.h"
#include "stdlib.h"

int strs_wc[10] = {5, 3, 5, 4, 4, 4, 2, 1};
char strs[10][100] = {
	"Hai I am is there",
	"Srinivas from Kadapa",
	"Aura Neworks a this Training",
	" Aura Neworks a Training",
	"Aura   Neworks a Training ",
	" Aura   Neworks a Training   ",
	"  a     g   ",
	"  a    "
};

main()
{
	int wc = 0, i = 0;

	for (i = 0; i < 8; i++)
	{
		wc = get_word_count(strs[i]);

		if (wc != strs_wc[i])
		{
			printf("-->%d.Failure: actual wc :%d, expected wc :%d, %s\n", i+1, wc, strs_wc[i], strs[i]);
		}
		else
		{
			printf("-->%d.Success: actual wc :%d, expected wc :%d, %s\n", i+1, wc, strs_wc[i], strs[i]);
		}


	}
}
