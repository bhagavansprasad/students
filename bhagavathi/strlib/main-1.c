#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "defs.h"

struct my_strings
{
	char s1[100];
	char s2[100];
};

struct my_strings test_strings[20] = {
#if 0
	{"try one more time",     	"try one more time"},
	{"try one more tim",      	"try one more tim"},
	{"AuraNetworks",          	"Aura Networks"},
	{"Aura eworks",           	"Aura etworks"},
	{"Ara NewOrks",           	"Ara NetwOrks"},
	{"Aur Networks",          	"Aura Networks"},
	{"Aa Ntworks",            	"Aa Networks"},
	{"Aua Netrks",            	"Aura Netrks"},
	{"Aura nETworks",         	""},
	{" ",                     	"Aura nETworks"},
#endif
	{"",                      	"Aura Networ"},
#if 0
	{" ",                      	"Aura Networ"},
	{"    ", "------"}
#endif
	{"",                      	"Aura Networ"},
};

main()
{
	int retval = 0, i = 0;
	char s1[12]="my world";
	char s2[12]="";

	//retval = astrcmp(s1, s2);
	for (i = 0; i< sizeof(test_strings)/sizeof(struct my_strings); i++)
	{
		//printf("s1:s2 --> %s:%s\n", test_strings[i].s1, test_strings[i].s2);

		retval = astrcmp(test_strings[i].s1, test_strings[i].s2);
		if(retval == 1)
			printf("SAME:     %s <--> %s\n", test_strings[i].s1, test_strings[i].s2);
		else
			printf("NOT SAME: %s <--> %s\n", test_strings[i].s1, test_strings[i].s2);
	}

#if 0
	m = astrncmp(s1,s2,l);
	if(m==1)
		printf("\nthe given at nth str is same :%s,%s,%d\n\n",s1,s2,l);
	else
	 	printf("\nthe given str at nth  is diff :%s,%s,%d\n\n",s1,s2,l);
#endif

}

