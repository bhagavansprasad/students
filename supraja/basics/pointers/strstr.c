#include<stdio.h>
#include<string.h>
char *astrstr(char *s,char *d)
{
	int i,j;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;d[j]!='\0';j++)
		{
			if(s[i]==d[j])
			{
				printf("%c\n",s[i]);
			}
			else
			{
				continue;
			}
		}
	}
}
int main()
{
	char st1[]="aura networks";
	char st2[]="net";
	astrstr(st2,st1);
}




