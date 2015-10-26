#include <stdio.h>
char astrlwr(char ch)
{
	if(ch >= 65 && ch <= 90)
		ch=ch+32;
	return ch;
}
main()
{
	char s1[]="banGALORE";
	char s2[15];
	int i;
	char j=0;
	for(i=0;s1[i];i++)
	{
		j = astrlwr(s1[i]);
		s2[i]=j;
	}
	s2[i]='\0';
	printf("s2 in lwer is %s\n",s2);
}
