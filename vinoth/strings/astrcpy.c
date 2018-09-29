#include <stdio.h>
main ()
{
	char s1[100] = "iam coming from bangalore";
	char s2[100];
	astrcpy(s1,s2);
	printf("%s\n",s2); 
}

int astrcpy(char *s1, char*s2)
{
	int i = 0;
	for (i=0; s1[i]!='\0'; i++)
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
}

