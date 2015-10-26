#include <stdio.h>
int pstrcmp(char *s1,char *s2)
{
	int i ;
	for(i=0;*s1==*s2;i++)
	{	
		if(*s1=='\0')
			return 0;
		s1++;
		s2++;
	}
	return (*s1-*s2);
	
}
main()
{
	char s1[]="bangalore";
	char s2[]="bangalore";
	int i = pstrcmp(s1,s2);
	if(!i)
		printf("strings are equal\n");
	else printf("strings are not equal\n");
}
