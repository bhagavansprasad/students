#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "defs.h"

#if 0
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
#endif

#include "stdio.h"
#include "defs.h"

main()
{
	int retval = 0, i = 0;
	char s1[]="aura netWORKS kaadubeesnahalli";
	char s2[]="aura networksKAADUBEESNAHALLI";
	char s3[100];

	retval = astrcmp(s1, s2);
	if(retval == 1)
		printf("SAME: %s and %s\n", s1, s2);
	else
		printf("NOT SAME :\"%s\" and \"%s\"\n", s1, s2);

	printf("Before astrcpy s3:%s, s1:%s\n", s3, s1);
	retval = astrcpy(s3, s1);
	printf("After  astrcpy s3:%s, s1:%s\n", s3, s1);
}

