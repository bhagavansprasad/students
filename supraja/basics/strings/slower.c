#include "stdio.h"

struct mystrings_t
{
	char s1[100];
};

struct mystrings_t strings[] = {
	{"Aura Networks"},
	{"Bangalore"},
	{"Kadapa"},
	{"K"},
	{"k"},
	{"K"},
	{"BANGLORE"},
	{"hai"},
	{"ha"},
	{"aura networks"},
	{"aura networks"},
};
main()
{
	int i,j;
	for(i=0;i<sizeof(strings)/sizeof(struct mystrings_t);i++)
	{
		astrtolower(strings[i].s1);
		printf("%s\n",strings[i].s1);
	}
}	
