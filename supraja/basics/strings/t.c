#include "stdio.h"

struct mystrings_t
{
	char s1[100];
	char s2[100];
	int  expr_casecmp;
	int  size;
	int  expr_casencmp;
};

struct mystrings_t strings[] = {
	{"Aura Networks", "AuRA NeTWorks", 0, 7, 0},
	{"Bangalore", "Baglre", -1, 3, -1},
	{"Kadapa", "Kdp", -1, 10, -1},
	{"K", "k", 0, 0, 0},
	{"k", "", -1, 2, -1},
	{"K", "K", 0, -1, 0},
	{"BANGLORE","banglore", 0, 4, 0},
	{"hai","hellow", -1, 4, -1},
	{"ha","  ", -1, 3, -1}
};

main()
{
	int i = 0;
	int retval = 0;

	printf("-->size of strings :%d\n", sizeof(strings));
	printf("-->size of mystrings_t :%d\n", sizeof(struct mystrings_t));

	for (i = 0; i < sizeof(strings)/sizeof(struct mystrings_t); i++)
	{
		//printf("-->%d. \'%s\' and \'%s\'\n", i+1, strings[i].s1, strings[i].s2);

		retval = astrncasecmp(strings[i].s1, strings[i].s2,strings[i].size);
		//printf("-->retval :%d, expr :%d\n", retval, strings[i].expr_casencmp);
		//retval = astrncasecmp(strings[i].s1, strings[i].s2, strings[i].size);
		if (retval == strings[i].expr_casencmp)
		{
			printf("-->PASS\n");
			printf("-->%d. SAME strings \'%s\' and \'%s\'\n", 
					i+1, strings[i].s1, strings[i].s2);
		}
		else
		{
			printf("-->retval :%d, expr :%d\n", retval, strings[i].expr_casencmp);
			printf("-->%d. FAIL SAME strings \'%s\' and \'%s\'\n", 
					i+1, strings[i].s1, strings[i].s2);
		}
	}
	
	return 0;
}
