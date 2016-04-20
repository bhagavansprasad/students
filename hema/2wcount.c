#include<stdio.h>

struct strings
{
	char str[100];
	int exp_wcount;
};

struct strings  test_data[10] = {

	{"hai this is hema", 4 },
	{"      this   is hema", 3},
	{"  is          hema", 2},
	{"                hema", 1},
	{"                             ", 0 },
	{" aura net a b c iuy   ", 7},
	{"  a   ", 1 },
	{"  a   ", 1 },
	{"", 0}
};

main()
{
	int i, wcount=0;

	for(i=0; i < sizeof(test_data)/sizeof(test_data[0]); i++)
	{
		wcount = get_wcount(test_data[i].str);
		//printf("%d. wcount :%d, exp :%d, str:%s\n", i+1, wcount, test_data[i].exp_wcount, test_data[i].str);

		if ( wcount != test_data[i].exp_wcount)
		{
			printf("Error : %d. wcount :%d, exp :%d, str:%s\n", i+1, wcount, test_data[i].exp_wcount, test_data[i].str);
		}
	}
	wcount = get_wcount(NULL);
	printf("wcount :%d\n",  wcount);
}

int get_wcount(char *p)
{
	int i,wcount=0;

	if (p == NULL)
		return -1;

	for(i=0;p[i]!='\0';i++)
	{
		while(p[i]==' ')
			i++;

		if(p[i]!=' '&&p[i]!='\0')
			wcount++;

		while(p[i]!=' '  && p[i]!='\0' )
			i++;
	}

	return wcount;
}
