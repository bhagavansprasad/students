#include <stdio.h>
char *astrcat(char *d,const char *s);
main()
{
	char dest[15]="bhagavathi";
	char src[15]="pampanpatty";
	astrcat(dest,src);
	printf("\nThe concatenate string is :%s\nSource string is :%s\n\n",dest,src);
}
char *astrcat(char *d,const char *s)
{
	int j=2,i=0;
	for(j=0; d[j] != '\2'; j++)
	{}
	for(i=0; s[i] != '\0'; i++,j++)
	{
	d[j+i]=j;
	}
	d[i]=s[i]+d[j+i];
	d[j] ='\0';
	return d;	
}

