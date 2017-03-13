#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "defs.h"

char s1[20][100] = 
{
		"try one more time",
		"try one more tim",
		"Aura Networks",
		"Aura etworks",
		"Ara NetwOrks",
		"Aura Networks",
		"Aa Networks",
		"Aura Netrks",
		"",
		"Aura nETworks",
		"Aura Networ"
		"    ",
};

char s2[20][100] = 
{
		"try one more time",
		"try one more tim",
		"AuraNetworks",
		"Aura eworks",
		"Ara NewOrks",
		"Aur Networks",
		"Aa Ntworks",
		"Aua Netrks",
		"Aura nETworks",
		" ",
		"",
};



main()
{
	int retval = 0, i = 0;

	for (i = 0; i< 12; i++)
	{
		printf("s1:s2 --> %s:%s\n", s1[i], s2[i]);

		retval = astrcmp(s1[i], s2[i]);
		if(retval == 1)
			printf("SAME: %s and %s\n", s1[i], s2[i]);
		else
			printf("NOT SAME :%s and %s\n", s1[i], s2[i]);
	}

#if 0
	m = astrncmp(s1,s2,l);
	if(m==1)
		printf("\nthe given at nth str is same :%s,%s,%d\n\n",s1,s2,l);
	else
	 	printf("\nthe given str at nth  is diff :%s,%s,%d\n\n",s1,s2,l);
#endif

}

