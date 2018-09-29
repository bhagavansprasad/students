#include <stdio.h>
#include <string.h>
char * astrcat(char *s1,char *s2)
{
	int i ,j;
	j=strlen(s1);
	for(i=0;s2[i]!='\0';i++,j++)
	{
		s1[j]=s2[i];
	}
	s1[j]='\0';
}
main()
{
	char s1[]="hello";
	char s2[]="world";
	astrcat(s1,s2);
	printf("s1 is %s \n",s1);
}
