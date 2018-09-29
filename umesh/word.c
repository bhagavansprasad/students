#include<stdio.h>
main()
{
	char s[100]="hello             world";
	int word,i;
	if (s[0]>=65 && s[i]<=122)
	{
		word++;
	}
	for(i=1;s[i]!='\0';i++)
	{
		if(s[i]==' ')
		{
			continue;
		}
		else
			if((s[i-1]>=65 && s[i-1]<=122)^(s[i]>=65 && s[i]<=122))
			{
				word++;
			}
	printf("%c",s[i]);
	}
	printf("%d",word);
}
