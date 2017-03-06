#include "stdio.h"
#include "astr.h"

char t1[100] = "Aura Networks";
char t2[100] = "Aura etworks";
char t3[100] = "Ara NetwOrks";
char t4[100] = "Aura Networks";
char t5[100] = "Aa Networks";
char t6[100] = "Aura Netrks";
char t7[100] = "Aura nETworks";
char t8[100] = "Aura Networks";
char t9[100] = "AURaNetworks";

main()
{
	char s1[100] = "Aura Networks";
	char s2[100];

	printf("Before strcpy s1 :%s\n", s1);
	printf("Before strcpy s2 :%s\n", s2);
	astrcpy(s2, s1);
	printf("After strcpy s1 :%s\n", s1);
	printf("After strcpy s2 :%s\n", s2);

	astrncpy(s2, s1, 5);
	printf("After strncpy s1 :%s\n", s1);
	printf("After strncpy s2 :%s\n", s2);
	astrncpy(s2, s1, 1000);
	astrncpy(s2, s1, 1);
	astrncpy(s2, s1, -10);
	astrncpy(s2, s1, 0);

	astrcmp(t1, t2);
	astrcmp(t3, t2);
	astrcmp(t7, t6);

	astrncmp(t1, t2, 2);
	astrncmp(t3, t2, 3);
	astrncmp(t7, t6, 8);
	astrncmp(t7, t6, 100);

}
