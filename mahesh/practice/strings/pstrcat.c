#include <stdio.h>
#include <string.h>
char *pstrcat(char *s1,char *s2)
{	
	int i;
	for(i=0;*s1;i++)
	{
		s1++;
	}
	for(i=0;*s2;i++)
	{
		*s1=*s2;
		s1++;
		*s2++;
	}
	*s1='\0';
}
main()
{
	char s1[]="hello";
	char s2[]="world";
	pstrcat(s1,s2);
	printf("after strcat s1 is %s\n",s1);
}
