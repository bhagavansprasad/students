#include <stdio.h>
void astrncpy(char*s2, char*s1, int n)
{
int i;
	for(i=0;i<n&&(s2[i]=s1[i]);i++);
//	{
		//s2[i]=s1[i];
//	}
	s2[i]='\0';
//	printf("%s\n",s2);
}
