#include <stdio.h>
int find_firstNR(char *s)
{
	int i,j;
	for(i=0;s[i];i++)
	{
		for(j=0;s[j];j++)
		{
			if(s[i]==s[j] && i!=j)
			break;
		}
		if(s[j]=='\0')
		return i;
	}
}
main()
{
	char s[]="suresh kumar srivastava";
	printf("%d\n",find_firstNR(s));
}
