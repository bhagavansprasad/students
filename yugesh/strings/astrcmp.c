#include <stdio.h>
int astrcmp(char*s1, char*s2)
{
	int i,flag=0;
	for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
	{
		if(s1[i]!=s2[i])
			flag=1;
	}
	if((s1[i]!='\0'&&s2[i]=='\0')||(s1[i]=='\0'&&s2[i]!='\0'))
			flag=1;
			return(flag);
}
