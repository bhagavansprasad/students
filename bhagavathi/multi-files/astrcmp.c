#include <stdio.h>
main()
{
	int x=0;
	char s1[100] = "Aura Networks";
	char s2[100] = "Aura etworks";
	char s3[100] = "Ara NetwOrks";
	char s4[100] = "Aura Networks";
	char s5[100] = "Aa Networks";
	char s6[100] = "Aura Netrks";
	char s7[100] = "Aura nETworks";
	char s8[100] = "Aura Networks";
	char s9[100] = "AURaNetworks";
	x = astrcmp(s2,s3);
	if(x==1)
	{
		printf("the str is same: %s,%s,%s\n",s2,s3);
	}
	else
	{
		printf("the str is different:%s,%s,%s\n",s2,s3);
	}
}
int astrcmp(char *s2, char *s3)
{
	int i=0;
	for(i=0; s2[i] != '\0'; i++)
		if(s2[i] != s3[i])
		{
			return 0;
		}
	return 1;
}
