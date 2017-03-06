#include "stdio.h"
#include "astr.h"

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

}
