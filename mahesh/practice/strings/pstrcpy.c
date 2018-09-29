#include <stdio.h>
char *pstrcpy(char *s2,char *s1)
{
	int i;
	for(i=0;*s2=*s1;i++)
	{
		s1++;
		s2++;
	}
	*s2='\0';
}
main()
{
	char s1[]="bangalore";
	char s2[15];
	pstrcpy(s2,s1);
	printf("s2 is %s\n",s2);
}
