#include <stdio.h>
char astrcat(char *d,char *s);
main()
{
	char s1[50]= "aura netwok";
	char s2[50]= "aura netwok bangalore";
	astrcat(s1,s2);																			
	printf("\nThe concatenate string is :%s\nSource string is  :%s\n", s1,s2 );
}
char astrcat(char *d,char *s)
{
	int i=0, j=0;
	for(i=0; d[i] != '\0'; i++);
		for(j=0; s[j] != '\0'; j++,i++)
			d[i]=s[j];
			return d[i];	
}
