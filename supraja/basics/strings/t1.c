#include "stdio.h"

struct mystrings_t
{
	char s1[100];
	char s2[100];
	int size;
};

struct mystrings_t strings[] = {
	{"Aura Networks", "AuRA NeTWorks",7},
	{"Bangalore", "Bangalore",5},
	{"Kadapa", "Kdp",1},
	{"K", "k",5},
	{"k", "",4},
	{"K", "K",3},
	{"BANGLORE","banglore",3},
	{"hai","hellow",3},
	{"ha","  ",2},
	{"aura networks","aura banglore",2},
	{"aura networks","aura netwobang",3}
};

main()
{
	int i =0;
	int retval = 0;

	for (i = 0; i < sizeof(strings)/sizeof(struct mystrings_t); i++)
	{
		//printf("-->%d. \'%s\' and \'%s\'\n", i+1, strings[i].s1, strings[i].s2);

		retval = astrncasecmp(strings[i].s1, strings[i].s2,strings[i].size );
		if (retval == 0)
		{
			printf("-->%d. SAME strings \'%s\' and \'%s\'\n", 
					i+1, strings[i].s1, strings[i].s2);
		}
		else
		{
			printf("-->%d. NOT SAME strings \'%s\' and \'%s\'\n", 
					i+1, strings[i].s1, strings[i].s2);
		}

	
	}
	
	return 0;
}
