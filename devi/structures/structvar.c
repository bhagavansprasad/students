#include <stdio.h>
#include "structdec.h"
#if 0
struct test
{
	char data[100];
	int count;
};
#endif

struct test strs[100] = {
	{"Aura networks", 2},
	{"netwoking is imp", 3},
	{"bangalore", 1},
	{"     ", 0}
};

main()
{
	int i,wrdcnt=0;
	for (i=0;i<=3;i++)
	{
		printf("%s\t",strs[i].data);
		printf("%d\t\n",strs[i].count);
		wrdcnt=getwordcount(strs[i].data);
		if(wrdcnt!=strs[i].count)
			printf("\n%d\n",wrdcnt);
	}
}
