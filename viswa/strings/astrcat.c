#include <stdio.h>
char *astrcat(char * , char *);


main()
{
	char s1[100] = "amruthala";
	char s2[100] = " viswanath";
	char *s;
	s = astrcat(s1 , s2);
	printf("srtcat ::%s\n",s);
}

char *astrcat(char *s1, char *s2)
{
	int i,j;
	for(i = 0; s1[i] !='\0'; i++);
	for(j = 0; s1[i] = s2[j]; i++,j++);
	return s1;
}
