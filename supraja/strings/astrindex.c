#include<stdio.h>
#include<string.h>
int astrindex(char *s,int n)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==n)
		break;
			//printf("%d",i);
	}
	return (i);
}
int main()
{
    int t;
	char s1[]="aura networks";
	char ch='r';
	t=astrindex(s1,ch);
	printf("%d\n",t);
}
