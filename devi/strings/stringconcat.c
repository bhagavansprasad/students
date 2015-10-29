#include <stdio.h>
char *astrcat(char *s1,char *s2)
{
	int i,j;
	for(i=0;*s1!='\0';i++,s1++);
	for(j=0;*s2!='\0';++i)
	{
		*s1 = *s2;	
		s1++;
		s2++;
	}
}
main()
{
	char s1[100] = "string";
	char s2[50] = "concatenation";
	astrcat(s1,s2);
	printf("s1-->%s\ts2-->%s\n",s1,s2);
}
