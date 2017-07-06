#include <stdio.h>
//int astrcmp (char *a, char*b);
//int astrncmp (char *c, char*d, int n);
main()
{
	int m=0,x=0,l=-6;
//	char s1[100]="try one more time";
//	char s2[100]="try one more tim";
	char s1[100] = "Aura Networks";
//	char s2[100] = "Aura etworks";
//	char s1[100] = "Ara NetwOrks";
//	char s2[100] = "Aura Networks";
//	char s1[100] = "Aa Networks";
//	char s2[100] = "Aura Netrks";
//	char s1[100] = "Aura nETworks";
	char s2[100] = "Aura Networ";

	x = astrcmp(s1,s2);
	m = astrncmp(s1,s2,l);
	if(x==1)
		printf("\nthe given str is same :%s,%s\n\n",s1,s2);
	else
		printf("\nthe given str is diff :%s,%s\n\n",s1,s2);
	if(m==1)
		printf("\nthe given at nth str is same :%s,%s,%d\n\n",s1,s2,l);
	else
	 	printf("\nthe given str at nth  is diff :%s,%s,%d\n\n",s1,s2,l);

}

